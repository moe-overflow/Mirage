#include "Window.hpp"

#include <glm/vec4.hpp>


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
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Mirage-Engine", NULL, NULL);

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
		glClearColor(0.52f, 0.37f, 0.832f, 1.0f);

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

	glfwTerminate();

	return 0;

}


void mirage::window::destroy()
{
	
}


