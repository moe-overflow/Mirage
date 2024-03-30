#include <stdexcept>
#include "shader.hpp"
#include "glad/glad.h"

namespace mirage
{
    shader::shader(mirage::shader_type type, const char* src) :
        _type { type },
        _id { glCreateShader(type) },
        _src { src }
    {
        create();
    }

    shader::~shader()
    {
        glDeleteShader(_id);
    }

    void shader::create()
    {
        glShaderSource(_id, 1, &_src, nullptr);
        glCompileShader(_id);

        check_errors();

    }

    GLuint shader::get() const
    {
        return _id;
    }

    void shader::check_errors() const
    {
        // Checking run time errors after calling 'glCompileShader()'
        int result;
        char message[512];
        glGetShaderiv(_id, GL_COMPILE_STATUS, &result);
        if(!result)
        {
            glGetShaderInfoLog(_id, 512, nullptr, message);
            throw std::runtime_error("An error occurred when compiling shader: {}" + std::string(message));
        }
    }


}
