#pragma once
#include <functional>
#include <string>

#include "Event.h"
#include "../Core.h"


namespace mirage
{
#define EVENT_CLASS_TYPE(type)  static event_type get_static_type() { return event_type::##type; }\
								virtual event_type get_event_type() const override { return get_static_type();}\
								virtual std::string get_name() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int get_category_flags() const override { return category; }

	enum class event_type
	{
		none = 0,
		window_close, window_resize,
		app_tick, app_update, app_render,
		key_pressed, key_released,
		mouse_button_pressed, mouse_button_released, mouse_scrolled, mouse_moved
	};

	enum event_category
	{
		none = 0,
		event_category_application =	BIT(0),
		event_category_input =			BIT(1),
		event_category_keyboard =		BIT(2),
		event_category_mouse =			BIT(3),
		event_category_mouse_button =	BIT(4)

	};

	/**
	 * \brief base class for events
	 *
	 */
	class MIRAGE_API event
	{
		virtual event_type get_event_type() const = 0;
		virtual std::string get_name() const = 0;
		virtual std::string to_string() const { return get_name(); }
		virtual int get_category_flags() const = 0; // todo: 

		inline bool is_in_category(event_category category) const
		{
			return get_category_flags() & category;
		}

		friend class event_dispatcher;

	private:
		bool handled_ = false;
		
	};


	
	/**
	 * \brief todo: ???
	 */
	class event_dispatcher
	{
		template<typename T>
		using event_func = std::function<bool(T&)>;
	public:
		/**
		 * \brief xy
		 * \param event : event to dispatch
		 */
		event_dispatcher(event& event) : event_(event) {};

		template<typename T>
		bool dispatch()
		{
			if(event_.get_event_type() == T::get_static_type())
			{
				event_.handled_ = func(*static_cast<T*>(&event_)); //  func(*(T*)&event_);
				return true;
			}
			return false;
		}

	private:
		event& event_;
	};
	




}
