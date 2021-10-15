#ifndef _Disciples_Disciples_h_
#define _Disciples_Disciples_h_

#include "../Engine/Graphics/Canvas.h"
#include "../Engine/Managers/FontManager.h"
#include "../Engine/Managers/TextManager.h"
#include "../Engine/Managers/ImageManager.h"
#include "../Engine/Managers/XmlManager.h"
#include "../Engine/Managers/LanguageManager.h"
#include "../Engine/Graphics/Camera.h"
#include "../Engine/GUI/Factory.h"
#include "Game/Settings.h"
#include "Tests/All.h"

namespace Disciples
{
	class Execute
	{
	public:
		Execute(const std::string& StartPath);
		void Run();
	private:
		Game::Settings _Settings;
		Arc::Graphics::Canvas _Canvas;
		Arc::Graphics::Camera _Camera;
		Arc::Managers::FontManager _FontManager;
		Arc::Managers::TextManager _TextManager;
		Arc::Managers::ImageManager _ImageManager;
		Arc::Managers::XmlManager _XmlManager;
		Arc::Managers::LanguageManager _LanguageManager;
		Arc::GUI::Factory _Factory;
		Arc::GUI::Application* _Application;
		Tests::All _All;
	};
}

#endif