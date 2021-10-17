#include "Stat.h"

using namespace Fallout;

int Gameplay::Stat::Value(size_t index)
{
	return _Stats.at(index).Value();
}

int Gameplay::Stat::Number(size_t index)
{
	return _Stats.at(index).Number();
}

int Gameplay::Stat::Percent(size_t index)
{
	return _Stats.at(index).Percent();
}

void Gameplay::Stat::Value(size_t index, int value)
{
	_Stats.at(index).Value(value);
}

void Gameplay::Stat::Number(size_t index, int value)
{
	_Stats.at(index).Number(value);
}

void Gameplay::Stat::Percent(size_t index, int value)
{
	_Stats.at(index).Percent(value);
}

int Gameplay::Stat::Get(size_t index)
{
    int result = 0;
    int number = Number(index);
    int percent = Percent(index);
    int value = Value(index);

    if (number > 0)
    {
        result += number;
    }
    else if (number < 0)
    {
        result -= number;
    }

    if (percent > 0)
    {
        result += (int)floor(double(value) / double(100) * percent);
    }
    else if (percent < 0)
    {
        result -= (int)floor(double(value) / double(100) * percent);
    }

    return result + value;
}