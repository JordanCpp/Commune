#include <cassert>
#include "ProtoManager.h"
#include "../Managers/ProtoManager.h"

using namespace Fallout;
using namespace Tests;

ProtoManager::ProtoManager()
{
	Managers::ProtoManager protoManager("Fallout\\");

	Arc::Common::XmlReader* xml = protoManager.Tile("Default.xml");

	assert(xml != nullptr);

	xml->NextOpening("Tile");
}