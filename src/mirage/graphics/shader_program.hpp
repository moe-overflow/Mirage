#pragma once

#include "glad/glad.h"
#include "shader.hpp"
#include <string>

namespace mirage
{

    class shader_program
    {
    public:
        shader_program();
        ~shader_program();
        void use() const;
        void unuse() const;
        void attach_shaders();
        void link();
        void check_errors() const;
        void set_uniform(const std::string& name, float r, float g, float b) const;
        [[nodiscard]] uint32_t get() const { return *_id; }
        void animate(const std::string& uniform_name) const;

    private:
        std::unique_ptr<shader> _vertex_shader;
        std::unique_ptr<shader> _fragment_shader;
        std::unique_ptr<uint32_t> _id;
    };

}

