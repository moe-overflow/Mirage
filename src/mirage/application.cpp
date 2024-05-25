#include "pchheader.h"
#include "application.hpp"
#include "utility/callback_functions.hpp"

namespace mirage
{
	application::application() :
        _window(std::make_unique<window>(WIDTH, HEIGHT)), _renderer(std::make_unique<renderer>())
	{ }


	void application::run()
	{
        _renderer->set_clear_color(0.0f, 0.0f, 0.0f, 1.0f);

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