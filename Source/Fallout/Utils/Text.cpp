#include "Text.h"

using namespace Fallout::Utils;

bool Text::ContainsPercent(const std::string& value)
{
	size_t found = value.find('%');

	return found != std::string::npos;
}

int Text::ParsePercent(const std::string& value)
{
    std::string number;

    size_t found = value.find('%');

    if (found != std::string::npos)
    {
        for (size_t i = 0; i < found; i++)
        {
            number.push_back(value[i]);
        }

        return std::stoi(number);
    }

    return std::stoi(value);
}

bool Text::IsInt(const std::string& value)
{
    if (value.size() == 0)
    {
        return false;
    }

    for (size_t i = 0; i < value.size(); i++)
    {
        if (!isdigit(value[i]))
        {
            return false;
        }
    }

    return true;
}
