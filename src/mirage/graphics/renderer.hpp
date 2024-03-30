#pragma once

#include "shader_program.hpp"
#include "buffer.hpp"
#include "../utility/log.hpp"

namespace mirage
{
    class renderer
    {
    public:
        renderer();
        ~renderer() = default;
        void render();
        void set_clear_color(float r, float g, float b, float a);
        void clear();
        void draw_triangle();
        static void log_info();

    private:
        shader_program _shader_program;
        buffer _buffer;
    };

}
