#pragma once

#include "Core.h"

namespace OGL {
	class OGL_API App
	{
	public:
		virtual ~App();
		void Run();
	};

	App* CreateApp();
	//DEFINED IN APP
}

