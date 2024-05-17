#include "pch.hpp"
#include "renderer.hpp"

namespace mirage
{
    GLfloat vertices[] =
    {
            -0.5f, 0.5f, 0.0f,
            0.0f, 0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
            -0.5f,  -0.5f, 0.0f,
            0.25f,  -0.25f, 0.0f,
            0.25f,  0.75f, 0.0f,
            -0.25f,  0.75f, 0.0f
    };

    GLuint indices[] = {
            0, 1, 2,
            0, 2, 3,
            1, 2, 4,
            1, 4, 5,
            1, 5, 6,
            0, 1, 6,
    };

    mirage::renderer::renderer()
    {
        log_info();

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        _shader_program = new shader_program();
        _vertex_array = new vertex_array();
        _vertex_buffer = new vertex_buffer();
        _index_buffer = new index_buffer();

        _vertex_array->bind();

        _index_buffer->bind();
        _index_buffer->buffer_data(sizeof(indices), indices);

        _vertex_buffer->bind();
        _vertex_buffer->buffer_data(sizeof(vertices), vertices);


        // todo: wrap attributes functionality

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                              3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        _vertex_buffer->unbind();
        _vertex_array->unbind();

        GLenum error = glGetError();
        if (error != GL_NO_ERROR)
        {
            MIRAGE_LOG_ERROR("OpenGL error: {}", error);
        }

        // todo: set uniform variables here...
        //_shader_program->set_uniform("myColor", 0.6039f, 0.4863f, 0.3843f);

    }

    renderer::~renderer()
    {
        delete _vertex_array;
        delete _vertex_buffer;
        delete _index_buffer;
        delete _shader_program;
    }

    void mirage::renderer::render()
    {
        _shader_program->bind();

        // _shader_program->bind();
        _vertex_array->bind();
        _shader_program->animate("myColor");

        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, std::size(indices), GL_UNSIGNED_INT, 0);

        _vertex_array->unbind();


        _shader_program->unbind();
    }

    void mirage::renderer::set_clear_color(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void mirage::renderer::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void mirage::renderer::log_info()
    {
        MIRAGE_LOG_INFO("GPU vendor: {}", reinterpret_cast<char const*> (glGetString(GL_VENDOR)));
        MIRAGE_LOG_INFO("GPU renderer: {}", reinterpret_cast<char const*> (glGetString(GL_RENDERER)));
        MIRAGE_LOG_INFO("GPU version: {}", reinterpret_cast<char const*> (glGetString(GL_VERSION)));
        MIRAGE_LOG_INFO("shading language: {}", reinterpret_cast<char const*> (glGetString(GL_SHADING_LANGUAGE_VERSION)));

        int nrAttributes;
        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
        MIRAGE_LOG_INFO("Maximum number of vertex attributes supported: {}", nrAttributes);
    }


}