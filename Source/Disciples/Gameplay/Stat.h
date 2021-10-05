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
			Max = 8
		};
		int GetValue(size_t index);
		int GetNumber(size_t index);
		int GetPercent(size_t index);
		int GetStat(size_t index);
	private:
		std::array<StatValue, Stat::Max> _Stats;
	};
}

#endif