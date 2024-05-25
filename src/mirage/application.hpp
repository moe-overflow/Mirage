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
		~application() = default;
		void run();

    private:
        std::unique_ptr<window> _window;
        std::unique_ptr<renderer> _renderer;

    };

	// to be defined in CLIENT
	application* create_application();
}
