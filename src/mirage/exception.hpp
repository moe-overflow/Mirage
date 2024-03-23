
#include <exception>

namespace mirage
{
	enum class mirage_exception_type
	{
		none = 0,

		not_allowed_event_type,


	};

	class mirage_exception : std::exception
	{
	public:
		mirage_exception(mirage::mirage_exception_type type) : _type(type)
		{

		}

	private:
		mirage_exception_type _type;
	
	};

}