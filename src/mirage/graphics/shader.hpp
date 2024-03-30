#pragma once

#include "glad/glad.h"
#include <string>

namespace mirage
{

    enum shader_type : GLenum
    {
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER,

    };


    class shader
    {
    public:
        shader() = delete;
        explicit shader(shader_type type, const char* src);
        shader(shader const&) = delete;
        shader(shader&&) = delete;
        ~shader();
        void create();
        [[nodiscard]] GLuint get() const;
        void check_errors() const;

    private:
        GLuint _id;
        const char* _src;
        shader_type _type;
    };
}
