#pragma once
#include <sstream>

#include "Event.hpp"

namespace mirage
{
	/**
	 * \brief base class for key event 
	 */
	class MIRAGE_API key_event : public event
	{
	public:
		inline int get_key_code() const { return key_code_; }

		EVENT_CLASS_CATEGORY(event_category_input | event_category_keyboard);

	protected:
		key_event(int key_code) : key_code_(key_code) {}
		int key_code_;
	};

	// sub classes of key_event

	class MIRAGE_API key_pressed_event : public key_event
	{
		public:

		/**
		 * \brief 
		 * \param key_code  
		 * \param key_count amount of time the key has been repeated. It could act like a bool
		 */
		key_pressed_event(const int key_code, const int key_count)
			: key_event(key_code), key_count_(key_count) {}

		inline int get_repeat_count() const { return key_count_; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "Key pressed event: (key:" << key_code_ << ", repeat count:" << key_count_ << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(key_pressed);

	private:
		int key_count_;
	};

	class MIRAGE_API key_released_event : public key_event
	{
	public:
		key_released_event(const int key_code) : key_event(key_code) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "Key released event: (key:" << key_code_ << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(key_released);
	};
}
