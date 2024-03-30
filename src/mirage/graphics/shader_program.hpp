#pragma once

#include "glad/glad.h"

namespace mirage
{
    static const char* vertex_shader_src = R"(
        #version 330 core
        layout (location = 0) in vec3 pos;
        void main()
        {
            gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
        }
    )";

    static const char* fragment_shader_src = R"(
        #version 330 core
        out vec4 color;
        void main()
        {
            color = vec4(0.490f, 0.247f, 0.058f, 1.0f);
        }
    )";

    class shader_program
    {
    public:
        shader_program();
        shader_program(shader_program const&) = delete;
        shader_program(shader_program&&) = delete;
        ~shader_program();
        void bind() const;
        void unbind() const;
        void check_errors() const;

    private:
        GLuint _id;

    };

}

