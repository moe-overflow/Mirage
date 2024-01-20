#pragma once


namespace mirage
{

    // Will be inherited from subclasses of clients
	class application
	{
	public:
		application();
		virtual ~application();
		void run();
	};

	// to be defined in CLIENT
	application* create_application();
}
