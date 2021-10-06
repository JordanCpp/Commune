#ifndef _Disciples_Gameplay_Stat_h_
#define _Disciples_Gameplay_Stat_h_

#include <array>
#include "StatValue.h"

namespace Gameplay
{
	class Stat
	{
	public:
		enum
		{
			HitPoints,
			HitPointsMax,
			Limit
		};
		int Value(size_t index);
		int Number(size_t index);
		int Percent(size_t index);
		void Value(size_t index, int value);
		void Number(size_t index, int value);
		void Percent(size_t index, int value);
		int GetStat(size_t index);
	private:
		std::array<StatValue, Stat::Limit> _Stats;
	};
}

#endif