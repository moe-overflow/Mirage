#pragma once

#include "event.hpp"

namespace mirage
{
	enum class window_event_type
	{
		window_resize,
		window_close,

	};


	class window_event : event
	{
	public:
		window_event(window_event_type type, int x, int y) : _type(type), _x(x), _y(y)
		{}

		window_event(window_event_type type) : _type(type), _x(-1), _y(-1)
		{}

		window_event_type get_type() { return _type; }
		int get_x() { return _x; }
		int get_y() { return _y; }


	private:
		window_event_type _type;
		int _x, _y;
	};

}