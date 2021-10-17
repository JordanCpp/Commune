#include <cassert>
#include "ProtoManager.h"
#include "../Managers/ProtoManager.h"

using namespace Fallout;
using namespace Tests;

ProtoManager::ProtoManager()
{
	Managers::ProtoManager protoManager("Fallout\\");

	assert(protoManager.Tile("Default.xml") != nullptr);
}