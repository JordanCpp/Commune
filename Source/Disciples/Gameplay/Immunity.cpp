#include "Immunity.h"

using namespace Gameplay;

bool Immunity::Get(size_t index)
{
    return _Value.at(index);
}

void Immunity::On(size_t index)
{
    _Value.at(index) = true;
}

void Immunity::Off(size_t index)
{
    _Value.at(index) = false;
}