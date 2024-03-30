#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "utility/Log.hpp"
#include "event_system/event_handler.hpp"


namespace mirage
{
	class window : public event_handler
	{

	public:
		window(int width, int height);
		~window();
        void init();
		void create();
		void destroy();
        GLFWwindow& get();
        [[nodiscard]] bool should_close() const;
        void swap_buffers();
        void poll_events();
        [[nodiscard]] bool key_pressed(int key);
        void close();

	private:
        bool _initialized = false;
        GLFWwindow* _instance = nullptr;
        int _width, _height;

		static void set_input_pointer_functions(GLFWwindow* window);


	};

}