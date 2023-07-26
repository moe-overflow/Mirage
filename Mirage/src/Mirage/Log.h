#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>


namespace mirage 
{
	class MIRAGE_API log
	{
	public: 
		static void init();

		inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return core_logger_; }
		inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return client_logger_; }
		
	private:
		static std::shared_ptr<spdlog::logger> core_logger_;
		static std::shared_ptr<spdlog::logger> client_logger_;


	};

}


// logging macros core
#define MIRAGE_CORE_INFO(...)	::mirage::log::get_core_logger()->info(__VA_ARGS__) 
#define MIRAGE_CORE_ERROR(...)	::mirage::log::get_core_logger()->error(__VA_ARGS__) 
#define MIRAGE_CORE_WARN(...)	::mirage::log::get_core_logger()->warn(__VA_ARGS__)
#define MIRAGE_CORE_TRACE(...)  ::mirage::log::get_core_logger()->trace(__VA_ARGS__) 
#define MIRAGE_CORE_FATAL(...)  ::mirage::log::get_core_logger()->fatal(__VA_ARGS__)
								  		  
// logging macros client		  		  
#define MIRAGE_INFO(...)		::mirage::log::get_client_logger()->info(__VA_ARGS__) 
#define MIRAGE_ERROR(...)		::mirage::log::get_client_logger()->error(__VA_ARGS__) 
#define MIRAGE_WARN(...)		::mirage::log::get_client_logger()->warn(__VA_ARGS__)
#define MIRAGE_TRACE(...)		::mirage::log::get_client_logger()->trace(__VA_ARGS__) 
#define MIRAGE_FATAL(...)		::mirage::log::get_client_logger()->fatal(__VA_ARGS__)
