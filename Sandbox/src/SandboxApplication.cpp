//#include <Mirage.h>
#include "../../Mirage/include/Mirage.hpp"
// todo: fix include <Mirage.h> . Include directory of project should be set by premake
#include <array>
#include <vector>
#include <random>


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


//int main()
//{
//	SandboxApplication* app = new SandboxApplication();
//	app->Run();
//	delete app;
//}

mirage::application* mirage::create_application()
{
	return new client_application();
}