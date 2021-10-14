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
		Graphics::Canvas _Canvas;
		Graphics::Camera _Camera;
		Managers::FontManager _FontManager;
		Managers::TextManager _TextManager;
		Managers::ImageManager _ImageManager;
		Managers::XmlManager _XmlManager;
		Managers::LanguageManager _LanguageManager;
		GUI::Factory _Factory;
		GUI::Application* _Application;
		Tests::All _All;
	};
}

#endif