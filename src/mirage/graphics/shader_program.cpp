#include "shader_program.hpp"
#include "shader.hpp"
#include "utility/log.hpp"

namespace mirage
{

    shader_program::shader_program()
    {
        _id = glCreateProgram();

        // vertex shader
        shader vertex_shader(shader_type::VERTEX, vertex_shader_src);
        glAttachShader(_id, vertex_shader.get());

        // fragment shader
        shader fragment_shader(shader_type::FRAGMENT, fragment_shader_src);
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
                MIRAGE_LOG_ERROR("An error occurred when compiling shader: {}", message);
            }
    }


}


