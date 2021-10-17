#include "StatValue.h"

using namespace Fallout;

Gameplay::StatValue::StatValue() :
	_Percent(0),
	_Number(0),
	_Value(0)
{
}

int Gameplay::StatValue::Value()
{
	return _Value;
}

int Gameplay::StatValue::Number()
{
	return _Number;
}

int Gameplay::StatValue::Percent()
{
	return _Percent;
}

void Gameplay::StatValue::Value(int value)
{
	_Value = value;
}

void Gameplay::StatValue::Number(int value)
{
	_Number = value;
}
void Gameplay::StatValue::Percent(int value)
{
	_Percent = value;
}