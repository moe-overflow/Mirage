#include "../../include/mirage.hpp"


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

//
//int main()
//{
//    std::cout << "Hello, here is MIRAGE ENGINE. WELCOME SIR!" << std::endl;
//
//    return 0;
//}