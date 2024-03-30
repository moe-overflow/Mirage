#include "renderer.hpp"

float vertex_positions[] = {
        0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
};

mirage::renderer::renderer()
{
    log_info();
    _buffer.buffer_data(vertex_positions);
}

void mirage::renderer::render()
{

}

void mirage::renderer::set_clear_color(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);

}

void mirage::renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void mirage::renderer::draw_triangle()
{
    set_clear_color(0.6039, 0.4863, 0.3843, 1.0f);
    clear();

    _shader_program.bind();
    _buffer.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void mirage::renderer::log_info()
{
    MIRAGE_LOG_INFO("GPU vendor: {}", reinterpret_cast<char const*> (glGetString(GL_VENDOR)));
    MIRAGE_LOG_INFO("GPU renderer: {}", reinterpret_cast<char const*> (glGetString(GL_RENDERER)));
    MIRAGE_LOG_INFO("GPU version: {}", reinterpret_cast<char const*> (glGetString(GL_VERSION)));
    MIRAGE_LOG_INFO("shading language: {}", reinterpret_cast<char const*> (glGetString(GL_SHADING_LANGUAGE_VERSION)));

}
