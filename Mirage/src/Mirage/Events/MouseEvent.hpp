#pragma once
#include <sstream>

#include "Event.hpp"

namespace mirage
{

	// todo: remove??!
	class MIRAGE_API mouse_button_event : public event
	{
	public:
		inline int get_button_key() const { return button_key_; }
		EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input)

	protected:
		mouse_button_event(int button) : button_key_(button) {}
		
		int button_key_;
	};


	class MIRAGE_API mouse_button_pressed_event : public mouse_button_event
	{
	public:
		mouse_button_pressed_event(const int button) : mouse_button_event(button) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "mouse_button_pressed_event (" << button_key_ << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_button_pressed)
	};

	class MIRAGE_API mouse_button_released_event : public mouse_button_event
	{
	public:
		mouse_button_released_event(const int button) : mouse_button_event(button) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "mouse_button_released_event (" << button_key_ << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_button_released)
	};


	class MIRAGE_API mouse_scrolled_event : public event
	{
	public:
		mouse_scrolled_event(float x_offset, float y_offset)
			: x_offset_(x_offset), y_offset_(y_offset) {}

		inline float get_x_offset() const { return x_offset_; }
		inline float get_y_offset() const { return y_offset_; }

		EVENT_CLASS_TYPE(mouse_scrolled)
		EVENT_CLASS_CATEGORY(event_category_input | event_category_mouse)

	private:
		float x_offset_, y_offset_;
	};


	class MIRAGE_API mouse_moved_event : public event
	{
	public:
		mouse_moved_event(float x, float y) : mouse_x_(x), mouse_y_(y) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "mouse_moved_event (" << mouse_x_ << ", " << mouse_y_ << ")";
			return ss.str();
		}

		inline float get_mouse_x() const { return mouse_x_; }
		inline float get_mouse_y() const { return mouse_y_; }

		EVENT_CLASS_TYPE(mouse_moved)
		EVENT_CLASS_CATEGORY(event_category_input | event_category_mouse)

	private:
		float mouse_x_, mouse_y_;
	};


}