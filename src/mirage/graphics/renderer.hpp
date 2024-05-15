#pragma once

#include "shader_program.hpp"
#include "buffer.hpp"
#include "../utility/log.hpp"
#include "vertex_array.hpp"
#include "GLFW/glfw3.h"
#include <cmath>

namespace mirage
{
    class renderer
    {
    public:
        renderer();
        ~renderer();
        void render();
        void set_clear_color(float r, float g, float b, float a);
        void clear();
        static void log_info();

    private:
        shader_program* _shader_program;
        vertex_array* _vertex_array;
        vertex_buffer* _vertex_buffer;
        index_buffer* _index_buffer;

    };

}
