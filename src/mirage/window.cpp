#include "window.hpp"
#include "event_system/event_handler.hpp"

static auto constexpr vertex_shader_src = R"(
        #version 330 core
        layout (location = 0) in vec3 pos;
        void main()
        {
            gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
        }
    )";

static auto constexpr fragment_shader_src = R"(
        #version 330 core
        out vec4 color;
        void main()
        {
            color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    )";


static int check_shader_errors(GLuint shader)
{
    // Checking compile time errors after calling 'glCompileShader()'
    int result;
    char message[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if(!result)
    {
        glGetShaderInfoLog(shader, 512, NULL, message);
        MIRAGE_LOG_ERROR("An error occurred when compiling shader: {}", message);
        return 1;
    }
    return 0;
}

static int check_program_errors(GLuint program)
{
    // Checking compile time errors after calling 'glCompileShader()'
    int result;
    char message[512];
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    if(!result)
    {
        glGetProgramInfoLog(program, 512, NULL, message);
        MIRAGE_LOG_ERROR("An error occurred when compiling shader: {}", message);
        return 1;
    }
    return 0;
    /**/
}

int mirage::window::create(int width, int height)
{
	glfwInit();

	// telling glfw about the used OpenGL version (3.3): 
	// note: when using these version, legacy OpenGL is disabled
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

	GLFWwindow* window = glfwCreateWindow(width, height, "Mirage-Engine", nullptr, nullptr);
	set_input_pointer_functions(window);

	if (window == nullptr)
	{
		MIRAGE_LOG_ERROR("Error while creating window");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// After making context, glad is going to be initialized:
	// maybe assertion?! from return value of gladLL (int)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		MIRAGE_LOG_ERROR("Error while initializing GLAD");
        this->destroy();
        return -1;
	}

	glViewport(0, 0, width, height);
	MIRAGE_LOG_INFO("Graphics driver: {}", reinterpret_cast<char const*> (glGetString(GL_VERSION)));

	/**/

	// create shader object
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);

	// attach source code of shader and compile it
	glShaderSource(vertex_shader, 1, &vertex_shader_src, nullptr);
	glCompileShader(vertex_shader);
	if (check_shader_errors(vertex_shader)) return 1;

	/**/

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_src, nullptr);
	glCompileShader(fragment_shader);
	if (check_shader_errors(fragment_shader)) return 1;
	/**/

	// link both shaders into a shader program

	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);
	check_program_errors(shader_program);

	/**/
	
	// delete shaders since they are now linked into program
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	/**/

	float vertex_positions[] = {
		0.0f,  0.5f, 0.0f,
	   -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f

	};

	GLuint vbo, vao;
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);

	// bind the buffer from which data should be processed (selecting a buffer)
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Copy vertex data (vertex_positions) into buffers memory 
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertex_positions, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	while (!glfwWindowShouldClose(window))
	{
		process_input(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader_program);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
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

        default:

            break;
	}

	mirage::key_event e (key, type);
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
        default:
            break;
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

void mirage::window::process_input(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, true);
    }
}

