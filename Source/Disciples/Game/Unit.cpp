#include "Unit.h"

using namespace Game;

Gameplay::Stat& Unit::Stat()
{
	return _Stat;
}

Gameplay::Ward& Unit::Ward()
{
	return _Ward;
}

Gameplay::Immunity& Unit::Immunity()
{
	return _Immunity;
}