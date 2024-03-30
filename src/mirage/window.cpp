#include "window.hpp"
#include "utility/callback_functions.hpp"

mirage::window::window(int width, int height) :
    _width{width},
    _height{height}
{
    create();
    _initialized = true;
}

mirage::window::~window()
{

}

void mirage::window::init()
{
    _initialized = glfwInit();
    if(!_initialized)
        throw std::runtime_error("GLFW initialization failed!");

    MIRAGE_LOG_INFO("GLFW was initialized successfully");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

}

void mirage::window::create()
{
    init();
    _instance = glfwCreateWindow(_width, _height, "Mirage-Engine", nullptr, nullptr);
	set_input_pointer_functions(_instance);

	if (_instance == nullptr)
	{
		MIRAGE_LOG_ERROR("Error while creating window");
		this->destroy();
		return;
	}

    MIRAGE_LOG_INFO("Window was created successfully");

	glfwMakeContextCurrent(_instance);
    glfwSetFramebufferSizeCallback(_instance, mirage::framebuffer_size_callback);

    // After making context, glad is going to be initialized:
	// maybe assertion?! from return value of gladLL (int)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		throw std::runtime_error("Error while initializing GLAD");
	}

}

bool mirage::window::should_close() const
{
    return glfwWindowShouldClose(_instance);
}

void mirage::window::poll_events()
{
    glfwPollEvents();
}

void mirage::window::swap_buffers()
{
    glfwSwapBuffers(_instance);
}

void mirage::window::destroy()
{
    glfwTerminate();
    _instance = nullptr;
}

GLFWwindow& mirage::window::get()
{
    return *_instance;
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

bool mirage::window::key_pressed(int key)
{
    return glfwGetKey(_instance, key);
}

void mirage::window::close()
{
    glfwSetWindowShouldClose(_instance, GLFW_TRUE);
}







