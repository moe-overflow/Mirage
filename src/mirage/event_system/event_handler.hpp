#pragma once

#include "key_event.hpp"
#include "window_event.hpp"
#include "mouse_event.hpp"
#include "../utility/log.hpp"

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
#ifdef EVENT_LOG
				MIRAGE_LOG_INFO("Key {} was pressed", e.get_key_code());
#endif
				break;
			}
			case mirage::key_event_type::key_released_event:
			{
#ifdef EVENT_LOG
				MIRAGE_LOG_INFO("Key {} was released", e.get_key_code());
#endif
				break;
			}
			case mirage::key_event_type::key_repeat_event:
			{
#ifdef EVENT_LOG
				MIRAGE_LOG_INFO("Key {} was repeated", e.get_key_code());
#endif
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
				case mirage::mouse_event_type::mouse_pointer_moved:
				{
					//auto *casted_e = dynamic_cast<mirage::mouse_cursor_moved*>(&e);
#ifdef EVENT_LOG
					MIRAGE_LOG_INFO("MOUSE CURSOR MOVED TO: ({}, {})", casted_e->get_x(), casted_e->get_y());
#endif
					break;
			
				}
				case mirage::mouse_event_type::mouse_pointer_entered:
				{
					/*
					mirage::mouse_cursor_entered* casted_e = dynamic_cast<mirage::mouse_cursor_entered*>(&e);
					MIRAGE_LOG_INFO("MOUSE CURSOR HAS ENTERED THE WINDOW");
					break;
					*/
					auto *casted_e = dynamic_cast<mirage::mouse_cursor_entered*>(&e);
					const std::string state(casted_e->is_within_window() ? "ENTERED" : "LEFT");
#ifdef EVENT_LOG
					MIRAGE_LOG_INFO("MOUSE CURSOR HAS {} THE WINDOW", state);
#endif
					break;
				}
				/*
				case mirage::mouse_event_type::mouse_pointer_left:
				{
					MIRAGE_LOG_INFO("MOUSE CURSOR HAS LEFT THE WINDOW");
					break;
				}
				*/
				case mirage::mouse_event_type::mouse_button_clicked:
				{
#ifdef EVENT_LOG
					MIRAGE_LOG_INFO("MOUSE CURSOR CLICKED");
#endif
					break;
				}
				case mirage::mouse_event_type::mouse_button_released:
				{
#ifdef EVENT_LOG
					MIRAGE_LOG_INFO("MOUSE CURSOR RELEASED");
#endif
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
#ifdef EVENT_LOG
					MIRAGE_LOG_INFO("WINDOW RESIZE ({}, {})", e.get_x(), e.get_y());
#endif
					break;
				}
				case mirage::window_event_type::window_close:
				{
#ifdef EVENT_LOG
					MIRAGE_LOG_INFO("WINDOW CLOSED");
#endif
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