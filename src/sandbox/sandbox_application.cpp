#include "mirage.hpp"

class client_application : public mirage::application
{
public:
	client_application()
	{

    }

	~client_application()
	{
		
	}
};

mirage::application* mirage::create_application()
{
	return new client_application();
}
