#pragma once
#include <iostream>

#include "Utilities/log.h"

#ifdef MIRAGE_PLATFORM_WINDOWS


/**
 * A function that will be define somewhere else and return the application (CLIENT)
 *
 */
extern mirage::application* mirage::create_application();

/*
 * main function of program. This is located in the engine itself in order to 
 * control the program secuence from here and not in clients
 *
 */
int main(int argc, char** argv)
{
	mirage::log::init();

	MIRAGE_CORE_WARN("logging system working?");
	MIRAGE_CLIENT_INFO("Yes!");


	auto app = mirage::create_application();
	app->run();
	delete app;
}

#endif