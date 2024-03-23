#include "application.hpp"

namespace mirage
{
	application::application()
	{
        _window = new window();
	}

	application::~application()
	{

	}

	void application::run()
	{
		// Game-Loop
		// while (true);

        _window->create(WIDTH, HEIGHT);

	}

}