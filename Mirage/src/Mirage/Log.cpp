#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace mirage
{
	std::shared_ptr<spdlog::logger> log::core_logger_;
	std::shared_ptr<spdlog::logger> log::client_logger_;
	
	/**
	* \brief 
	*
	*/
	void log::init()
	{
		// custom formatting
		spdlog::set_pattern("%^[%T] %n: %v%$");

		core_logger_ = spdlog::stdout_color_mt("MIRAGE");
		core_logger_->set_level(spdlog::level::trace);

		client_logger_ = spdlog::stdout_color_mt("CLIENT");
		client_logger_->set_level(spdlog::level::trace);

	}
}