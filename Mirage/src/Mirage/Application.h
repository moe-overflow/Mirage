#pragma once

#include "Core.h"

namespace Mirage
{
	// Will be inherited from subclasses of clients
	class MIRAGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// to be defined in CLIENT
	Application* CreateApplication();
}
