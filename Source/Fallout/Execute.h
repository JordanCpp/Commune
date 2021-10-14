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
		Graphics::Canvas _Canvas;
		Graphics::Camera _Camera;
		Managers::FontManager _FontManager;
		Managers::TextManager _TextManager;
		Managers::ImageManager _ImageManager;
		Managers::XmlManager _XmlManager;
		Managers::LanguageManager _LanguageManager;
		GUI::Factory _Factory;
		GUI::Application* _Application;
	};
}

#endif