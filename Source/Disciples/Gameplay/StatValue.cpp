#include "StatValue.h"

int Gameplay::StatValue::Percent()
{
	return _Percent;
}

int Gameplay::StatValue::Number()
{
	return _Number;
}

int Gameplay::StatValue::Value()
{
	return _Value;
}

void Gameplay::StatValue::Percent(int value)
{
	_Percent = value;
}

void Gameplay::StatValue::Number(int value)
{
	_Number = value;
}

void Gameplay::StatValue::Value(int value)
{
	_Value = value;
}