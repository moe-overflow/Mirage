#pragma once

#include "utility/log.hpp"
#include "window.hpp"
#include "application.hpp"

#ifdef MIRAGE_PLATFORM_WINDOWS

/**
 * A function that will be defined somewhere else and return the application (CLIENT)
 *
 */


/**
 * main function of program. This is located in the engine itself in order to 
 * control the program sequence from here and not in clients
 *
 */
int main(int argc, char** argv)
{
	mirage::logger::init();

	MIRAGE_LOG_INFO("Hello, Mirage Engine!");

	
	MIRAGE_LOG_INFO("Number of args {}", argc);

	for (int arg = 0; arg < argc; arg++)
	{
		MIRAGE_LOG_INFO("Command number {} is: {}", arg, argv[arg]);
	}

    auto app = mirage::create_application();
    app->run();
    delete app;

	// spdlog::shutdown();

}

#endif