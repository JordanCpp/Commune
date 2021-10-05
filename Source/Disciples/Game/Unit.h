#ifndef _Disciples_Game_Unit_h_
#define _Disciples_Game_Unit_h_

#include "../Gameplay/Ward.h"
#include "../Gameplay/Immunity.h"

namespace Game
{
	class Unit
	{
	public:
	private:
		Gameplay::Ward _Wards[8];
		Gameplay::Immunity _Immunities[8];
	};
}

#endif