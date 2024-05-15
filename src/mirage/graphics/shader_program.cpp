#include "shader_program.hpp"
#include "shader.hpp"
#include "utility/log.hpp"
#include "GLFW/glfw3.h"

namespace mirage
{

    shader_program::shader_program()
    {
        shader vertex_shader(shader_type::VERTEX, "shaders/vertex_shader.glsl");
        shader fragment_shader(shader_type::FRAGMENT, "shaders/fragment_shader.glsl");

        _id = glCreateProgram();

        glAttachShader(_id, vertex_shader.get());
        glAttachShader(_id, fragment_shader.get());

        glLinkProgram(_id);

        check_errors();

        glDetachShader(_id, vertex_shader.get());
        glDeleteShader(vertex_shader.get());

        glDetachShader(_id, fragment_shader.get());
        glDeleteShader(fragment_shader.get());

    }

    shader_program::~shader_program()
    {
        glUseProgram(0);
        glDeleteProgram(_id);
    }

    void shader_program::bind() const
    {
        glUseProgram(_id);
    }

    void shader_program::unbind() const
    {
        glUseProgram(0);
    }

    void shader_program::check_errors() const
    {
        // Checking compile time errors after calling 'glCompileShader()'
        int result;
        char message[512];
        glGetProgramiv(_id, GL_LINK_STATUS, &result);
        if(!result)
        {
            glGetProgramInfoLog(_id, 512, NULL, message);
            MIRAGE_LOG_ERROR("An error occurred when compiling shaders: {}", message);
        }

        GLenum error = glGetError();
        if (error != GL_NO_ERROR)
        {
            MIRAGE_LOG_ERROR("OpenGL error: {}", error);
        }

    }

    //todo: glm::vec3 instead of rgb
    void shader_program::set_uniform(const std::string& name, float r, float g, float b) const
    {
        int location = glGetUniformLocation(this->get(), name.c_str());
        assert(location != -1);
        glUniform4f(location, r, g, b, 1.0f);
    }

    void shader_program::animate(const std::string& uniform_name) const
    {
        float time_value = glfwGetTime();
        float red = 0.3f; // static
        float green = cos(time_value) * 0.5 + 0.5;
        float blue = sin(time_value) * 0.5 + 0.5;

        set_uniform(uniform_name, red, green, blue);

    }

}


