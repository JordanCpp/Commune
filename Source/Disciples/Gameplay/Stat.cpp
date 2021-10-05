#include "Stat.h"

int Gameplay::Stat::GetValue(size_t index)
{
    return _Stats.at(index).Value();
}

int Gameplay::Stat::GetNumber(size_t index)
{
    return _Stats.at(index).Number();
}

int Gameplay::Stat::GetPercent(size_t index)
{
    return _Stats.at(index).Percent();
}

int Gameplay::Stat::GetStat(size_t index)
{
    int result = 0;
    int number = GetNumber(index);
    int percent = GetPercent(index);
    int value = GetValue(index);

    if (number > 0)
    {
        result += value + number;
    }
    else if (number < 0)
    {
        result += value - number;
    }

    if (percent > 0)
    {
        result += value + (value / 100 * percent);
    }
    else if (percent < 0)
    {
        result += value - (value / 100 * percent);
    }

    return result;
}