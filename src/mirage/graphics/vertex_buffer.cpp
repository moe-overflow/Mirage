#include "buffer.hpp"

namespace mirage
{
    vertex_buffer::vertex_buffer()
    {
        glGenBuffers(1, &_id);
    }

    void vertex_buffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, _id);
    }

    void vertex_buffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void vertex_buffer::buffer_data(int size, GLfloat positions[]) const
    {
        glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);
    }

}