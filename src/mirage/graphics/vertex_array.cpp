#include "pch.hpp"
#include "vertex_array.hpp"

vertex_array::vertex_array()
{
    glGenVertexArrays(1, &_id);
}

void vertex_array::bind() const
{
    glBindVertexArray(_id);
}

void vertex_array::unbind() const
{
    glBindVertexArray(0);
}

