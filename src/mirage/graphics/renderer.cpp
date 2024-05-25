#include "pchheader.h"
#include "renderer.hpp"

#define draw_elements glDrawElements

namespace mirage
{

    void GLAPIENTRY DebugMessageCallback(
            GLenum source __attribute__((unused)),
            GLenum type __attribute__((unused)),
            GLuint id __attribute__((unused)),
            GLenum severity __attribute__((unused)),
            GLsizei length __attribute__((unused)),
            const GLchar* message,
            const void* userParam __attribute__((unused))
    )
    {
        MIRAGE_LOG_ERROR("Renderer Error: {} ", message);

    }

    mirage::renderer::renderer() : _render_entities(std::make_unique<std::vector<render_entity>>())
    {
        log_info();

        std::vector<render_entity_data> data =
        {
                {
                        {
                                -0.5f, 0.5f, 0.0f,
                                0.0f, 0.5f, 0.0f,
                                0.0f, -0.5f, 0.0f,
                                -0.5f,  -0.5f, 0.0f,
                                0.25f,  -0.25f, 0.0f,
                                0.25f,  0.75f, 0.0f,
                                //-0.25f,  0.75f, 0.0f


                        },
                        {
                                0, 1, 2,
                                0, 2, 3,
                                1, 2, 4,
                                1, 4, 5
                        }
                },
                {

                        {
                                -0.5f, 0.5f, 0.0f,
                                0.0f, 0.5f, 0.0f,
                                -0.25f,  0.75f, 0.0f,
                                0.25f,  0.75f, 0.0f
                        },
                        {
                                0, 1, 2,
                                1, 2, 3
                        }

                }
        };

        for (const auto& entity : data) {
            _render_entities->emplace_back(create_render_entity(entity));
        }


        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // debug!
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(DebugMessageCallback, 0);

    }

    void renderer::render()
    {
        for(const render_entity& entity : *_render_entities)
        {
            entity.ShaderProgram->use();
            entity.VertexArray->bind();
            entity.ShaderProgram->animate("myColor");
            draw_elements(GL_TRIANGLES,
                          static_cast<int>(entity.IndexBuffer->count()),
                          GL_UNSIGNED_INT,
                          0); // todo indices => variable
            entity.VertexArray->unbind();
            entity.ShaderProgram->unuse();
        }

        glDebugMessageCallback(DebugMessageCallback, 0);


    }

    void renderer::set_clear_color(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void renderer::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void renderer::log_info()
    {
        MIRAGE_LOG_INFO("GPU vendor: {}", reinterpret_cast<char const*> (glGetString(GL_VENDOR)));
        MIRAGE_LOG_INFO("GPU renderer: {}", reinterpret_cast<char const*> (glGetString(GL_RENDERER)));
        MIRAGE_LOG_INFO("GPU version: {}", reinterpret_cast<char const*> (glGetString(GL_VERSION)));
        MIRAGE_LOG_INFO("shading language: {}", reinterpret_cast<char const*> (glGetString(GL_SHADING_LANGUAGE_VERSION)));

        int nrAttributes;
        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
        MIRAGE_LOG_INFO("Maximum number of vertex attributes supported: {}", nrAttributes);
    }

    std::unique_ptr<render_entity> renderer::create_render_entity(const render_entity_data& data)
    {
        auto sp = std::make_unique<shader_program>();
        auto va = std::make_unique<vertex_array>();
        //std::make_unique<vertex_buffer>(sizeof(data.vertices), data.vertices),
        auto vb = std::make_unique<vertex_buffer>(data.vertices.size() * sizeof(float), data.vertices.data());
        auto ib = std::make_unique<index_buffer>(data.indices.size() * sizeof(int), data.indices.data());


        va->bind();
        vb->bind();
        vb->buffer_data(data.vertices.size() * sizeof(float), data.vertices.data()); // todo: redundant (see ctor)

        ib->bind();
        ib->buffer_data(data.indices.size() * sizeof(int), data.indices.data()); // todo: redundant (see ctor)


        vertex_buffer_layout layout1;
        layout1.push(shader_data_type::FLOAT, 3);
        va->add_vertex_buffer(*vb, layout1); // debug: breakpoint

        vb->unbind();

        sp->set_uniform("myColor", 1.0f, 1.0f, 1.0f);

        return std::make_unique<render_entity>(std::move(sp), std::move(va), std::move(vb), std::move(ib));
    }
}

