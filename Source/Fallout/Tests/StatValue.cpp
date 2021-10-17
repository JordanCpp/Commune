#include <cassert>
#include "StatValue.h"
#include "../Gameplay/StatValue.h"

using namespace Fallout;
using namespace Tests;

StatValue::StatValue()
{
  Gameplay::StatValue statValue;

  assert(statValue.Value() == 0);
  assert(statValue.Number() == 0);
  assert(statValue.Percent() == 0);

  statValue.Value(100);
  statValue.Number(15);
  statValue.Percent(25);

  assert(statValue.Value() == 100);
  assert(statValue.Number() == 15);
  assert(statValue.Percent() == 25);
}