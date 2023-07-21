#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>


namespace Mirage 
{
	class MIRAGE_API Log
	{
	public: 
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};

}


// logging macros core
#define MIRAGE_CORE_INFO(...)	::Mirage::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define MIRAGE_CORE_ERROR(...)	::Mirage::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define MIRAGE_CORE_WARN(...)	::Mirage::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MIRAGE_CORE_TRACE(...)  ::Mirage::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define MIRAGE_CORE_FATAL(...)  ::Mirage::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// logging macros client
#define MIRAGE_INFO(...)		::Mirage::Log::GetClientLogger()->info(__VA_ARGS__) 
#define MIRAGE_ERROR(...)		::Mirage::Log::GetClientLogger()->error(__VA_ARGS__) 
#define MIRAGE_WARN(...)		::Mirage::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MIRAGE_TRACE(...)		::Mirage::Log::GetClientLogger()->trace(__VA_ARGS__) 
#define MIRAGE_FATAL(...)		::Mirage::Log::GetClientLogger()->fatal(__VA_ARGS__)
