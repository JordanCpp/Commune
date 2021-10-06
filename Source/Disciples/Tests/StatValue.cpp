#include "StatValue.h"
#include <cassert>
#include "../Gameplay/StatValue.h"

using namespace Tests;

StatValue::StatValue()
{
	Gameplay::StatValue statValue;

	assert(statValue.Number() == 0);
	assert(statValue.Percent() == 0);
	assert(statValue.Value() == 0);

	statValue.Number(100);
	statValue.Percent(50);
	statValue.Value(75);

	assert(statValue.Number() == 100);
	assert(statValue.Percent() == 50);
	assert(statValue.Value() == 75);
}