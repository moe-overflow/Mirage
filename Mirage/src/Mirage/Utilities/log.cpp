#include "log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace mirage
{
	std::shared_ptr<spdlog::logger> log::core_logger_ ;
	std::shared_ptr<spdlog::logger> log::client_logger_ ;

	void log::init()
	{
		spdlog::set_pattern("[%T] %n:	%^ %v %$");
		core_logger_ = spdlog::stdout_color_mt("MIRAGE ENGINE");
		core_logger_->set_level(spdlog::level::debug);

		client_logger_ = spdlog::stdout_color_mt("CLIENT APPLICATION");
		client_logger_->set_level(spdlog::level::info);
		

	}


}
