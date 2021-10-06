#include "Stat.h"
#include "../Gameplay/Stat.h"
#include <cassert>
#include <stdio.h>

using namespace Tests;

Stat::Stat()
{
	Gameplay::Stat stat;

	assert(stat.GetStat(Gameplay::Stat::HitPoints) == 0);

	stat.Value(Gameplay::Stat::HitPoints, 100);
	assert(stat.GetStat(Gameplay::Stat::HitPoints) == 100);

	stat.Percent(Gameplay::Stat::HitPoints, 5);
	assert(stat.GetStat(Gameplay::Stat::HitPoints) == 105);

	stat.Number(Gameplay::Stat::HitPoints, 15);
	assert(stat.GetStat(Gameplay::Stat::HitPoints) == 120);
}