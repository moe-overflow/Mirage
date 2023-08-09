#pragma once

#include "../Core.h"
#include "spdlog/spdlog.h"

namespace mirage
{
	class MIRAGE_API log
	{
	public:
		static void init();

		static std::shared_ptr<spdlog::logger>& get_core_logger() { return core_logger_; }
		static std::shared_ptr<spdlog::logger>& get_client_logger() { return client_logger_; }


	private:
		static std::shared_ptr<spdlog::logger> core_logger_;
		static std::shared_ptr<spdlog::logger> client_logger_;


	};

}

#define MIRAGE_CORE_INFO(...)	mirage::log::get_core_logger()->info(__VA_ARGS__)
#define MIRAGE_CORE_DEBUG(...)	mirage::log::get_core_logger()->debug(__VA_ARGS__)
#define MIRAGE_CORE_WARN(...)	mirage::log::get_core_logger()->warn(__VA_ARGS__)
#define MIRAGE_CORE_ERROR(...)	mirage::log::get_core_logger()->error(__VA_ARGS__)

#define MIRAGE_CLIENT_INFO(...)		mirage::log::get_client_logger()->info(__VA_ARGS__)
#define MIRAGE_CLIENT_DEBUG(...)	mirage::log::get_client_logger()->debug(__VA_ARGS__)
#define MIRAGE_CLIENT_WARN(...)		mirage::log::get_client_logger()->warn(__VA_ARGS__)
#define MIRAGE_CLIENT_ERROR(...)	mirage::log::get_client_logger()->error(__VA_ARGS__)
