#pragma once

#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/sinks/basic_file_sink.h>

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

namespace mirage
{
	enum class log_message_level;

	class logger
	{
	public:
		
		static void init();
		//static void log(log_message_level level, const std::string& message);

		static std::shared_ptr<spdlog::logger>& get_engine_logger() { return engine_logger_; }
		static std::shared_ptr<spdlog::logger>& get_client_logger() { return client_logger_; }




	private:
		logger() = default;

		inline static std::shared_ptr<spdlog::logger> engine_logger_;
		inline static std::shared_ptr<spdlog::logger> client_logger_;
	};
	
}

#define MIRAGE_LOG_INFO(...)	  mirage::logger::get_engine_logger()->info(__VA_ARGS__)
#define MIRAGE_LOG_DEBUG(...)	  mirage::logger::get_engine_logger()->debug(__VA_ARGS__)
#define MIRAGE_LOG_WARN(...)	  mirage::logger::get_engine_logger()->warn(__VA_ARGS__)
#define MIRAGE_LOG_ERROR(...)	  mirage::logger::get_engine_logger()->error(__VA_ARGS__)
#define MIRAGE_LOG_CRITICAL(...)  mirage::logger::get_engine_logger()->critical(__VA_ARGS__)

#define CLIENT_LOG_INFO(...)	  mirage::logger::get_client_logger()->info(__VA_ARGS__)
#define CLIENT_LOG_DEBUG(...)	  mirage::logger::get_client_logger()->debug(__VA_ARGS__)
#define CLIENT_LOG_WARN(...)	  mirage::logger::get_client_logger()->warn(__VA_ARGS__)
#define CLIENT_LOG_ERROR(...)	  mirage::logger::get_client_logger()->error(__VA_ARGS__)	
#define CLIENT_LOG_CRITICAL(...)  mirage::logger::get_client_logger()->critical(__VA_ARGS__)	
