#ifndef _Arcanum_Execute_h_
#define _Arcanum_Execute_h_

#include <string>
#include "../Engine/Graphics/Canvas3D.h"

namespace Arcanum
{
	class Execute
	{
	public:
		Execute(const std::string& path);
		void Run();
	private:
		Arc::Graphics::Canvas3D _Canvas;
	};
}

#endif