#include "Global.h"

using namespace Fallout;

int Gameplay::Global::Get(const std::string& name)
{
	auto i = _Vars.find(name);

	return i->second;
}