#include "pch.hpp"
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
//        _renderer->set_clear_color(0.6039, 0.4863, 0.3843, 1.0f);

        while (!_window->should_close())
        {
            _window->poll_events();

            mirage::process_input(*_window);

            _renderer->clear();
            _renderer->render();

            _window->swap_buffers();
        }
	}

}