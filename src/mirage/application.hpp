#pragma once

#include "window.hpp"
#include "graphics/renderer.hpp"

namespace mirage
{
	static constexpr int WIDTH = 1920;
	static constexpr int HEIGHT = 1080;

	class application
	{
	public:
		application();
        application(application const&) = delete;
        application(application&&) = delete;
		virtual ~application();
		void run();

    private:
        window* _window;
        renderer* _renderer;


	};

	// to be defined in CLIENT
	application* create_application();
}
