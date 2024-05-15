#include "buffer.hpp"

namespace mirage
{

    index_buffer::index_buffer()
    {
        glGenBuffers(1, &_id);
    }

    void index_buffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
    }

    void index_buffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void index_buffer::buffer_data(int size, GLuint indices[])
    {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }



}