#include "Window.hpp"

#include <glm/vec4.hpp>
#include "event_system/event_handler.hpp"



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
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
	mirage::key_event_type type = mirage::key_event_type::none;

	switch(action)
	{
		case GLFW_PRESS:
			type = mirage::key_event_type::key_pressed_event;
			break;

		case GLFW_REPEAT:
			type = mirage::key_event_type::key_repeat_event;
			break;

		case GLFW_RELEASE:
			type = mirage::key_event_type::key_released_event;
			break;
	}

	mirage::key_event e (key, type );
	handle_key_event(e);

}

void mirage::window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	mirage::mouse_event_type type = mirage::mouse_event_type::none;

	switch (action)
	{
	case GLFW_PRESS:
		type = mirage::mouse_event_type::mouse_button_clicked;
		break;

	case GLFW_RELEASE:
		type = mirage::mouse_event_type::mouse_button_released;
		break;



	}

	mirage::mouse_event e(type, button);
	handle_mouse_event(e);

}

void mirage::window::cursor_callback(GLFWwindow *window, double x, double y)
{
	mirage::mouse_event e(mirage::mouse_event_type::mouse_cursor_moved, x, y);
	handle_mouse_event(e);
}

void mirage::window::cursor_enter_callback(GLFWwindow* window, int entered)
{
	bool in_window = entered == 1 ? true : false;
	mirage::mouse_event e(mirage::mouse_event_type::mouse_cursor_entered, in_window);
	handle_mouse_event(e);
}

void mirage::window::set_input_pointer_functions(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_callback);
	glfwSetCursorEnterCallback(window, cursor_enter_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	//glfwSetScrollCallback(window, );
	glfwSetWindowSizeCallback(window, window_resize_callback);
	glfwSetWindowCloseCallback(window, window_close_callback);

}


int mirage::window::create()
{
	glfwInit();
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Mirage-Engine", NULL, NULL);

	set_input_pointer_functions(window);


	if (window == NULL)
	{
		MIRAGE_LOG_ERROR("Error while creating window");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		MIRAGE_LOG_ERROR("Error while initializing GLAD");
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	std::cout << glGetString(GL_VERSION) << std::endl;

	/*
	// define vertex buffer
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // select buffer

	static constexpr int vertices_number = 6;
	float vertices[vertices_number] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};

	// put data into buffer
	glBufferData(GL_ARRAY_BUFFER, vertices_number * sizeof(float), vertices, GL_STATIC_DRAW);
	*/


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// background color
		glClearColor(0.92f, 0.327f, 0.232f, 1.0f);

		// Legacy OpenGL
		
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		

		glfwSwapBuffers(window);

		// any event triggered?
		glfwPollEvents();

	}

	destroy();

	return 0;

}


void mirage::window::destroy()
{
	glfwTerminate();
}


