#pragma once

#include "glad/glad.h"
#include <string>

namespace mirage
{

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
        void set_uniform(const std::string& name, float r, float g, float b) const;
        [[nodiscard]] int get() const { return _id; }
        void animate(const std::string& uniform_name) const;

    private:
        GLuint _id;

    };

}

