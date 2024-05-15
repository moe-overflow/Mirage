#pragma once

#include "glad/glad.h"
#include <GL/gl.h>

namespace mirage
{
    class buffer
    {
    public:

        ~buffer() = default;

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        [[nodiscard]] GLuint get() const { return _id; }

    protected:
        buffer() = default;

        GLuint _id;

    };

    class vertex_buffer : buffer
    {
    public:
        vertex_buffer();
        //~vertex_buffer() override;

        void bind() const override;
        void unbind() const override;

        void buffer_data(int size, float positions[]) const;

    };

    class index_buffer : buffer
    {
    public:
        index_buffer();
        //~index_buffer() override;

        void bind() const override;
        void unbind() const override;

        void buffer_data(int size, GLuint indices[]);
    };



}

