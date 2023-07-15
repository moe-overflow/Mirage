#include <Mirage.h>


class SandboxApplication : public Mirage::Application
{
public:
	SandboxApplication()
	{

	}

	~SandboxApplication()
	{

	}
};


//int main()
//{
//	SandboxApplication* app = new SandboxApplication();
//	app->Run();
//	delete app;
//}

Mirage::Application* Mirage::CreateApplication()
{
	return new SandboxApplication();
}