#pragma once

#include "event.hpp"

namespace mirage
{
	enum class mouse_event_type
	{
		none,
		mouse_button_clicked,
		mouse_button_released,
		mouse_cursor_moved,
		mouse_cursor_entered,
		mouse_wheel_scrolled,
	};


	class mouse_event : event 
	{
	public:

		mouse_event(mouse_event_type type, double x, double y) :
			_type(type), _x(x), _y(y)
		{}
		
		mouse_event(mouse_event_type type, bool cursor_within_window) :
			_cursor_within_window(cursor_within_window), _type(type)
		{}

		mouse_event(mouse_event_type type, int button) :
			_button(button), _type(type)
		{}


		double get_x() { return _x; }
		double get_y() { return _y; }
		mouse_event_type get_type(){ return _type; }
		bool is_within_window() { return _cursor_within_window; }

	private:
		int _x, _y;
		mouse_event_type _type;
		bool _cursor_within_window;
		int _button;


	};
	
}
