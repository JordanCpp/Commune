#include "Ward.h"

using namespace Gameplay;

uint8_t Ward::Get(size_t index)
{
	return _Value.at(index);
}

void Ward::Set(size_t index, uint8_t value)
{
	_Value.at(index) = value;
}