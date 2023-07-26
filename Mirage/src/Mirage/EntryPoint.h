#pragma once

#ifdef MIRAGE_PLATFORM_WINDOWS


/*
 * A function that will be define somewhere else and return the application (CLIENT)
 *
 */
extern mirage::application* mirage::create_application();

/*
 * main function of program. This is located in the engine itself in order to 
 * control the program secuence from here and not in clients
 *
 */
inline int main(int argc, char** argv)
{
	mirage::log::init();
	MIRAGE_CORE_ERROR("Engine initialized!");
	MIRAGE_WARN("Client initialized!"); 

	int a = 32;
	MIRAGE_CORE_INFO("value of variable a is {0}", a); 

	auto app = Mirage::CreateApplication();
	app->Run();
	delete app;
}

#endif