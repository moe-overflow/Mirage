#include "Window.hpp"



mirage::window::window()
{

}

mirage::window::~window()
{
	
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


int mirage::window::create()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Mirage-Engine", NULL, NULL);

	if(window == NULL)
	{
		MIRAGE_CORE_ERROR("Error while creating window");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		MIRAGE_CORE_ERROR("Error while initializing GLAD");
		return -1;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.52f, 0.37f, 0.832f, 1.0f);


		glfwSwapBuffers(window);
		// any event triggered?
		glfwPollEvents();

	}

	glfwTerminate();

	return 0;
}


void mirage::window::destroy()
{
	
}



