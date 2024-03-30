#include "buffer.hpp"

namespace mirage
{

    buffer::buffer()
    {
        // vertex buffer object
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // vertex buffer array
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

    }

    void buffer::buffer_data(float positions[])
    {
        // Copy vertex data (vertex_positions) into buffers memory
        glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positions, GL_STATIC_DRAW);
    }

    void buffer::bind() const
    {
        glBindVertexArray(vao);
    }

    void buffer::unbind()
    {
        glBindVertexArray(0);
    }


}

