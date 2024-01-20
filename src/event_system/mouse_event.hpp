#pragma once

#include "event.hpp"

namespace mirage
{
	enum class mouse_event_type
	{
		none = 0,
		mouse_button_clicked,
		mouse_button_released,
		mouse_pointer_moved,
		mouse_pointer_entered,
		//mouse_pointer_left,
		

		// mouse_wheel_scrolled

	};


	class mouse_event : event 
	{
		// todo: every mouse event type should be implemented as an own class. Typ controlling using dynamic_cast<>
	public:
		/*
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
		//bool is_within_window() { return _cursor_within_window; }

	protected:
		//int _x, _y;
		mouse_event_type _type;
		//bool _cursor_within_window;
		//int _button;

		*/


		mouse_event() : _type(mouse_event_type::none) {}
		mouse_event(mouse_event_type type) : _type(type) {}


		mouse_event_type get_type() { return _type; }


	public:
		mouse_event_type _type;
	};

	class mouse_button : public mouse_event
	{
	public: 
		mouse_button(mouse_event_type type, int button)
			: mouse_event(type), _button(button)
		{}

		mouse_button() : mouse_event(mouse_event_type::none), _button(-1)
		{}

	private:
		int _button;
	};

/*
	class mouse_button_clicked	: mouse_event
	{
	
	};							
			
	class mouse_button_released : mouse_event
	{
	
	};					


	_x, _y

*/					
							

	class mouse_cursor_entered : public mouse_event
	{
	public:

		mouse_cursor_entered(mouse_event_type type, bool in) : mouse_event(type), _cursor_within_window(in)
		{}

		bool is_within_window() { return _cursor_within_window; }
		void set_within_window(bool in) { _cursor_within_window = in; }

	private:
		bool _cursor_within_window;

	};

	class mouse_cursor_moved : public mouse_event
	{
	public:
		mouse_cursor_moved(mouse_event_type type, int x, int y)
			: mouse_event(type), _x(x), _y(y)
		{}

		int get_x() { return _x; }
		int get_y() { return _y; }

	private:
		int _x, _y;
	};

	class mouse_wheel_scrolled : public mouse_event
	{

	};

}
