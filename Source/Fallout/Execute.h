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
#include "Managers/SpriteManager.h"
#include "Tests/All.h"
#include "Managers/MsgManager.h"

namespace Fallout
{
	class Execute
	{
	public:
		Execute(const std::string& path);
		void Run();
	private:
		Tests::All _All;
		Game::Settings _Settings;
		Arc::Graphics::Canvas _Canvas;
		Arc::Graphics::Camera _Camera;
		Managers::MsgManager _MsgManager;
		Arc::Managers::FontManager _FontManager;
		Arc::Managers::TextManager _TextManager;
		Managers::SpriteManager _SpriteManager;
		Arc::Managers::XmlManager _XmlManager;
		Arc::Managers::LanguageManager _LanguageManager;
		Arc::GUI::Factory _Factory;
		Arc::GUI::Application _Application;
	};
}

#endif