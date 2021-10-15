#include "ProtoManager.h"

using namespace Fallout;
using namespace Managers;


ProtoManager::ProtoManager(const std::string& path):
	_XmlManager(path)
{
}

Arc::Common::XmlReader* ProtoManager::Proto(const std::string& dir, const std::string& file)
{
	return _XmlManager.GetReader(dir, file);
}

Arc::Common::XmlReader* ProtoManager::Critter(const std::string& file)
{
	return Proto("Critters\\", file);
}

Arc::Common::XmlReader* ProtoManager::Tile(const std::string& file)
{
	return Proto("Tiles\\", file);
}