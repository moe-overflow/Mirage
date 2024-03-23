#pragma once

#include "window.hpp"

namespace mirage
{
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;

	class application
	{
	public:
		application();
		virtual ~application();
		void run();

    private:
        window* _window;


	};

	// to be defined in CLIENT
	application* create_application();
}
