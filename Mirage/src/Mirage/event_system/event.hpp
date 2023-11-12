#pragma once

namespace mirage
{
	/*
	enum class event_type
	{
		key_event,
		mouse_event,
		window_event
		
		none = 0,

		window_resized,
		window_closed,

		key_clicked,
		key_released,

		mouse_cursor_moved,
		mouse_button_clicked,
		mouse_button_release
		
	};
	*/


	class event
	{
	protected:
		event() = default;

	public:
		bool handled{ false };

		virtual ~event() = default;
		//[[nodiscard]] virtual event_type get_type() const = 0;


	};


	

}

