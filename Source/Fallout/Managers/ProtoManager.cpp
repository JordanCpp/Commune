#include "ProtoManager.h"
#include "..\Tests\ProtoManager.h"

using namespace Fallout;
using namespace Managers;


ProtoManager::ProtoManager(const std::string& path):
	_XmlManagerBase(path),
	_XmlManagerParent(path)
{
}

Arc::Common::XmlReader* ProtoManager::Proto(const std::string& dir, const std::string& file)
{
	return _XmlManagerBase.GetReader(dir, file);
}

Arc::Common::XmlReader* ProtoManager::Critter(const std::string& file)
{
	return Proto("Prototypes\\Critters\\", file);
}

Arc::Common::XmlReader* ProtoManager::Parent(const std::string& file)
{
	return _XmlManagerParent.GetReader("Prototypes\\Critters\\Parents\\", file);;
}

Arc::Common::XmlReader* ProtoManager::Tile(const std::string& file)
{
	return Proto("Prototypes\\Tiles\\", file);
}