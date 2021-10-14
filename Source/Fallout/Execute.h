#ifndef _Fallout_Execute_h_
#define _Fallout_Execute_h_

#include <string>
#include "Game/Settings.h"
#include "../Engine/Graphics/Canvas.h"
#include "../Engine/Graphics/Camera.h"

namespace Fallout
{
	class Execute
	{
	public:
		Execute(const std::string& path);
		void Run();
	private:
		Fallout::Game::Settings _Settings;
		Graphics::Canvas _Canvas;
		Graphics::Camera _Camera;
	};
}

#endif