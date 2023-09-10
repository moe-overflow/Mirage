#include "Log.hpp"
namespace mirage
{

	void logger::init()
	{
		try
		{
			const auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
			console_sink->set_level(spdlog::level::info);

			const std::string log_file_path = "../../utilities/log_history/";

			const auto t = std::time(nullptr);
			const auto tm = *std::localtime(&t);

			std::ostringstream oss;
			oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
			const auto str = oss.str();

			const auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
				log_file_path  + str + ".log", true);
			file_sink->set_level(spdlog::level::info);

			get_engine_logger() = std::make_shared<spdlog::logger>("MIRAGE_CORE");
			get_client_logger() = std::make_shared<spdlog::logger>("MIRAGE_CLIENT");


			spdlog::register_logger(get_engine_logger());
			get_engine_logger()->sinks().push_back(console_sink);
			get_engine_logger()->sinks().push_back(file_sink);

			spdlog::register_logger(get_client_logger());
			get_client_logger()->sinks().push_back(console_sink);
			get_client_logger()->sinks().push_back(file_sink);
			
			spdlog::flush_every(std::chrono::seconds(3));

		}
		catch (spdlog::spdlog_ex& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}


}
