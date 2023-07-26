#pragma once

#include <sstream>

#include "Event.h"

namespace mirage
{
	class window_resize_event : public event
	{
	public:
		window_resize_event(unsigned int width, unsigned int height) : width_(width), height_(height) {}

		[[nodiscard]] unsigned int get_width() const { return width_; }
		[[nodiscard]] unsigned int get_height() const { return height_; }

		
		std::string to_string() const override
		{
			std::stringstream ss;
			ss <<  "Window resize event: (width:" << width_ << ", height : " << height_ << ")";
			return ss.str();
		}


		EVENT_CLASS_CATEGORY(event_category_application)
		EVENT_CLASS_TYPE(app_render)

	private:
		unsigned int width_, height_;
	};

	class window_close_event : public event
	{
	public:
		window_close_event();

		EVENT_CLASS_CATEGORY(event_category_application)
		EVENT_CLASS_TYPE(app_render)
	};

	class app_tick_event : public event
	{
	public:
		app_tick_event();

		EVENT_CLASS_CATEGORY(event_category_application)
		EVENT_CLASS_TYPE(app_render)
	};


	class app_update_event : public event
	{
	public:
		app_update_event();

		EVENT_CLASS_CATEGORY(event_category_application)
		EVENT_CLASS_TYPE(app_update)
	};

	class app_render_event : public event
	{
	public:
		app_render_event();

		EVENT_CLASS_CATEGORY(event_category_application)
		EVENT_CLASS_TYPE(app_render)
	};

}