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
		window() = default;
		~window() = default;
		int create();
		void destroy();
	
	private:
		void set_input_pointer_functions(GLFWwindow* window);

		
		// to get called when an appropriate event occurs
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void window_close_callback(GLFWwindow* window);
		static void window_resize_callback(GLFWwindow* window, int width, int height);
		static void key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_callback(GLFWwindow* window, double x, double y);
		static void pointer_enter_callback(GLFWwindow* window, int entered);



	private:
		static constexpr int width = 800;
		static constexpr int height = 600;



	};

}