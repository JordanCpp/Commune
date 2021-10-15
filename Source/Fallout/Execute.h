#ifndef _Fallout_Execute_h_
#define _Fallout_Execute_h_

#include <string>
#include "Game/Settings.h"
#include "../Engine/Graphics/Canvas.h"
#include "../Engine/Graphics/Camera.h"
#include "../Engine/Managers/FontManager.h"
#include "../Engine/Managers/TextManager.h"
#include "../Engine/Managers/ImageManager.h"
#include "../Engine/Managers/XmlManager.h"
#include "../Engine/Managers/LanguageManager.h"
#include "../Engine/GUI/Factory.h"

namespace Fallout
{
	class Execute
	{
	public:
		Execute(const std::string& path);
		void Run();
	private:
		Fallout::Game::Settings _Settings;
		Arc::Graphics::Canvas _Canvas;
		Arc::Graphics::Camera _Camera;
		Arc::Managers::FontManager _FontManager;
		Arc::Managers::TextManager _TextManager;
		Arc::Managers::ImageManager _ImageManager;
		Arc::Managers::XmlManager _XmlManager;
		Arc::Managers::LanguageManager _LanguageManager;
		Arc::GUI::Factory _Factory;
		Arc::GUI::Application* _Application;
	};
}

#endif