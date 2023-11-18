
#include <glm/vec4.hpp>

#include "window.hpp"
#include "event_system/event_handler.hpp"



int mirage::window::create()
{
	glfwInit();

	// telling glfw about the used OpenGL version (3.3): 
	// note: when using these version, legacy OpenGL is disabled
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(width, height, "Mirage-Engine", NULL, NULL);

	set_input_pointer_functions(window);


	if (window == NULL)	
	{
		MIRAGE_LOG_ERROR("Error while creating window");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// after making context, glad is gonna be initialized:
	// maybe assertion?! from return value of gladLL (int)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		MIRAGE_LOG_ERROR("Error while initializing GLAD");
		return -1;
	}

	glViewport(0, 0, width, height);

	MIRAGE_LOG_INFO(reinterpret_cast<char const*> (glGetString(GL_VERSION)));


	


	// background color
	glClearColor(0.92f, 0.327f, 0.232f, 1.0f);



	while (!glfwWindowShouldClose(window))
	{

		glClear(GL_COLOR_BUFFER_BIT);
		// Legacy OpenGL
		/*
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		*/

		glfwSwapBuffers(window);

		// any event triggered? (window will not be responding to events if not included!)
		glfwPollEvents();

	}

	destroy();

	return 0;

}


void mirage::window::destroy()
{
	glfwTerminate();
}


void mirage::window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mirage::window::window_close_callback(GLFWwindow* window)
{
	mirage::window_event e(mirage::window_event_type::window_close);
	handle_window_event(e);
}

void mirage::window::window_resize_callback(GLFWwindow* window, int width, int height)
{
	mirage::window_event e(mirage::window_event_type::window_resize, width, height);
	handle_window_event(e);
}

void mirage::window::key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods)
{
	mirage::key_event_type type = key_event_type::none;

	switch(action)
	{
		case GLFW_PRESS:
			type = key_event_type::key_pressed_event;
			break;

		case GLFW_REPEAT:
			type = key_event_type::key_repeat_event;
			break;

		case GLFW_RELEASE:
			type = key_event_type::key_released_event;
			break;
	}

	mirage::key_event e (key, type );
	handle_key_event(e);

}

void mirage::window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	
	mirage::mouse_button e;

	if (action == GLFW_PRESS) 
		e = mirage::mouse_button(mouse_event_type::mouse_button_clicked, button);

	else if(action == GLFW_RELEASE)
		e = mirage::mouse_button(mouse_event_type::mouse_button_released, button);
	
	
	handle_mouse_event(e);	

}

void mirage::window::cursor_callback(GLFWwindow *window, double x, double y)
{
	mirage::mouse_cursor_moved e(mouse_event_type::mouse_pointer_moved, x, y);
	handle_mouse_event(e);
}

void mirage::window::pointer_enter_callback(GLFWwindow* window, int entered)
{
	mirage::mouse_event_type type = mirage::mouse_event_type::none;
	bool in_window = false;

	switch (entered)
	{
		case 1:
		{
			type = mirage::mouse_event_type::mouse_pointer_entered;
			in_window = true;
			break;
		}
		case 0:
		{
			type = mirage::mouse_event_type::mouse_pointer_entered;
			in_window = false;
			break;
		}
	}
	
	mirage::mouse_cursor_entered e(type, in_window);
	handle_mouse_event(e);

}

void mirage::window::set_input_pointer_functions(GLFWwindow* window)
{
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwSetKeyCallback(window, key_callback);

	glfwSetCursorPosCallback(window, cursor_callback);
	glfwSetCursorEnterCallback(window, pointer_enter_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	//glfwSetScrollCallback(window, );

	glfwSetWindowSizeCallback(window, window_resize_callback);
	glfwSetWindowCloseCallback(window, window_close_callback);

}
