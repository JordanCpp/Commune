#include "StatValue.h"
#include "..\Tests\StatValue.h"

using namespace Gameplay;

StatValue::StatValue() :
	_Percent(0),
	_Number(0),
	_Value(0)
{
}

int StatValue::Percent()
{
	return _Percent;
}

int StatValue::Number()
{
	return _Number;
}

int StatValue::Value()
{
	return _Value;
}

void StatValue::Percent(int value)
{
	_Percent = value;
}

void StatValue::Number(int value)
{
	_Number = value;
}

void StatValue::Value(int value)
{
	_Value = value;
}