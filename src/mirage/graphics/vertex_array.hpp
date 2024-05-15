#pragma once

#include "glad/glad.h"
#include <GL/gl.h>

class vertex_array
{
public:
    vertex_array();
    //~index_buffer() override;

    void bind() const;
    void unbind() const;

private:
    GLuint _id{};
};

