#pragma once

#include "glad/glad.h"
#include <GL/gl.h>

namespace mirage
{
    class buffer
    {
    public:
        buffer();
        void buffer_data(float positions[]);
        void bind() const;
        void unbind() ;

    private:
        GLuint vbo;
        GLuint vao;

    };
}

