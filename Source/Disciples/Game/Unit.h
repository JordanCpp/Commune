#ifndef _Disciples_Game_Unit_h_
#define _Disciples_Game_Unit_h_

#include "../Gameplay/Stat.h"
#include "../Gameplay/Ward.h"
#include "../Gameplay/Immunity.h"

namespace Game
{
	class Unit
	{
	public:
		Gameplay::Stat& Stat();
		Gameplay::Ward& Ward();
		Gameplay::Immunity& Immunity();
	private:
		Gameplay::Stat _Stat;
		Gameplay::Ward _Ward;
		Gameplay::Immunity _Immunity;
	};
}

#endif