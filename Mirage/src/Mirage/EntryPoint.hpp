#pragma once

#include "Utilities/log.hpp"
#include <glm/glm.hpp>
#include "Window.hpp"

#ifdef MIRAGE_PLATFORM_WINDOWS


/**
 * A function that will be define somewhere else and return the application (CLIENT)
 *
 */
extern mirage::application* mirage::create_application();

/**
 * main function of program. This is located in the engine itself in order to 
 * control the program sequence from here and not in clients
 *
 */
int main(int argc, char** argv)
{
	mirage::logger::init();

	MIRAGE_LOG_INFO("Hello, Mirage Engine!");

	spdlog::shutdown();

	auto vec = glm::vec3{ 1.4, 4.6, 6.7 };

	MIRAGE_LOG_WARN("The coordinates of our vector are: "
		+ std::to_string(vec.x) + ", " +std::to_string(vec.y) + ", " + std::to_string(vec.z));

	CLIENT_LOG_CRITICAL("Sheehs");

	mirage::window window;
	window.create();

	auto app = mirage::create_application();
	app->run();
	delete app;
}

#endif