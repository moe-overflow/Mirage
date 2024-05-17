#include "pch.hpp"
#include "callback_functions.hpp"

namespace mirage
{

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void window_close_callback(GLFWwindow* window)
    {
        mirage::window_event e(mirage::window_event_type::window_close);
        window::handle_window_event(e);
    }

    void window_resize_callback(GLFWwindow* window, int width, int height)
    {
        mirage::window_event e(mirage::window_event_type::window_resize, width, height);
        window::handle_window_event(e);
    }

    void key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods)
    {
        mirage::key_event_type type = key_event_type::none;

        switch(action)
        {
            case GLFW_PRESS:
                type = key_event_type::key_pressed_event;
                break;

            case GLFW_REPEAT:
                type = key_event_type::key_repeat_event;
                break;

            case GLFW_RELEASE:
                type = key_event_type::key_released_event;
                break;

            default:

                break;
        }

        mirage::key_event e (key, type);
        window::handle_key_event(e);

    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        mirage::mouse_button e;

        if (action == GLFW_PRESS)
            e = mirage::mouse_button(mouse_event_type::mouse_button_clicked, button);

        else if(action == GLFW_RELEASE)
            e = mirage::mouse_button(mouse_event_type::mouse_button_released, button);


        window::handle_mouse_event(e);

    }

    void cursor_callback(GLFWwindow *window, double x, double y)
    {
        mirage::mouse_cursor_moved e(mouse_event_type::mouse_pointer_moved, x, y);
        window::handle_mouse_event(e);
    }

    void pointer_enter_callback(GLFWwindow* window, int entered)
    {
        mirage::mouse_event_type type = mirage::mouse_event_type::none;
        bool in_window = false;

        switch (entered)
        {
            case 1:
            {
                type = mirage::mouse_event_type::mouse_pointer_entered;
                in_window = true;
                break;
            }
            case 0:
            {
                type = mirage::mouse_event_type::mouse_pointer_entered;
                in_window = false;
                break;
            }
            default:
                break;
        }

        mirage::mouse_cursor_entered e(type, in_window);
        window::handle_mouse_event(e);

    }

    void process_input(mirage::window& window)
    {
        if( window.key_pressed(GLFW_KEY_ESCAPE))
        {
            window.close();
        }
    }

}
