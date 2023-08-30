#pragma once
#include "Core.hpp"

namespace mirage
{
	class MIRAGE_API window
	{
	public:
		window();
		~window();
		int create();
		void destroy();


	private:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
	};

}