#pragma once
#include "Core.hpp"

#include "Utilities/Log.hpp"
//#include <glad/gl.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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