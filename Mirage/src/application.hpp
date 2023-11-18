#pragma once

#include "core.hpp"

namespace mirage
{
	// Will be inherited from subclasses of clients
	class MIRAGE_API application
	{
	public:
		application();
		virtual ~application();
		void run();
	};

	// to be defined in CLIENT
	application* create_application();
}
