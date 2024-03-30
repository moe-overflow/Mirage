#include "application.hpp"
#include "utility/callback_functions.hpp"

namespace mirage
{

	application::application()
	{
        _window = new window(WIDTH, HEIGHT);
        _renderer = new renderer();
	}

	application::~application()
	{
        _window = nullptr;
        _renderer = nullptr;
	}

	void application::run()
	{

        while (!_window->should_close())
        {
            mirage::process_input(*_window);

            _renderer->draw_triangle();

            _window->swap_buffers();
            _window->poll_events();
        }
	}

}