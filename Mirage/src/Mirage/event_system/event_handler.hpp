#pragma once


#include "key_event.hpp"
#include "window_event.hpp"
#include "mouse_event.hpp"
#include <Mirage/utilities/log.hpp>

namespace mirage
{

	class event_handler
	{
	public:
			
		static void handle_key_event(key_event& e)
		{
			switch (e.get_type())
			{
			case mirage::key_event_type::key_pressed_event:
			{
				MIRAGE_LOG_INFO(std::format("Key {} was pressed", e.get_key_code()));
				break;
			}
			case mirage::key_event_type::key_released_event:
			{
				MIRAGE_LOG_INFO(std::format("Key {} was released", e.get_key_code()));
				break;
			}
			case mirage::key_event_type::key_repeat_event:
			{
				MIRAGE_LOG_INFO(std::format("Key {} was repeated", e.get_key_code()));
				break;
			}
			default:
				break;
			}
		}

		static void handle_mouse_event(mouse_event& e)
		{
			switch (e.get_type())
			{
				case mirage::mouse_event_type::mouse_cursor_moved:
				{
					MIRAGE_LOG_INFO(std::format("MOUSE CURSOR MOVED TO: ({}, {})", e.get_x(), e.get_y()));
					break;
			
				}
				case mirage::mouse_event_type::mouse_cursor_entered:
				{	
					const std::string state( e.is_within_window() ? " ENTERED" : "LEFT");
					MIRAGE_LOG_INFO("MOUSE CURSOR HAS {} THE WINDOW", state);
					break;
				}
				case mirage::mouse_event_type::mouse_button_clicked:
				{
					MIRAGE_LOG_INFO(std::format("MOUSE CURSOR CLICKED"));
					break;
				}
				case mirage::mouse_event_type::mouse_button_released:
				{
					MIRAGE_LOG_INFO(std::format("MOUSE CURSOR RELEASED"));
					break;
				}

				
				{
				default: 
					break;
				}
			}
		}

		static void handle_window_event(window_event& e)
		{
			switch (e.get_type())
			{
				case mirage::window_event_type::window_resize:
				{
					MIRAGE_LOG_INFO(std::format("WINDOW RESIZE ({}, {})", e.get_x(), e.get_y()));
					break;
				}
				case mirage::window_event_type::window_close:
				{
					MIRAGE_LOG_INFO(std::format("WINDOW CLOSED"));
					break;
				} 
				{
				default:
					break;
				}
			}
		}
	};

}