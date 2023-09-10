#include "Application.hpp"
#include <iostream>

namespace mirage
{
	application::application()
	{

	}

	application::~application()
	{
		
	}

	void application::run()
	{
		std::cout << "Hello Mirage!\n";
		
		while (true);
	}

}