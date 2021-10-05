#ifndef _Disciples_Gameplay_StatValue_h_
#define _Disciples_Gameplay_StatValue_h_

#include "Immunity.h"
#include "Ward.h"

namespace Gameplay
{
	class StatValue
	{
	public:
		int Percent();
		int Number();
		int Value();
		void Percent(int value);
		void Number(int value);
		void Value(int value);
	private:
		int _Percent;
		int _Number;
		int _Value;
	};
}

#endif