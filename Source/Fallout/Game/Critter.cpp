#include "Critter.h"

using namespace Fallout;

Game::Critter::Critter(const std::string& protoFile, Managers::ProtoManager* protoManager)
{
	auto base = protoManager->Critter(protoFile);

	base->NextOpening("Critter");

	base->NextNode("Parent");
	auto parent = protoManager->Parent(base->Value());
	ReadParent(parent);

	base->NextClosing("Critter");
}

void Game::Critter::ReadStat(Arc::Common::XmlReader* reader, size_t stat, const std::string& name)
{
	reader->NextNode(name);
	_Stat.Value(stat, reader->ValueInt());
}

void Game::Critter::ReadParent(Arc::Common::XmlReader* reader)
{
	reader->NextOpening("Critter");

	ReadStat(reader, Gameplay::Stat::Strength, "Strength");
	ReadStat(reader, Gameplay::Stat::Perception, "Perception");
	ReadStat(reader, Gameplay::Stat::Endurance, "Endurance");
	ReadStat(reader, Gameplay::Stat::Charisma, "Charisma");
	ReadStat(reader, Gameplay::Stat::Intelligence, "Intelligence");
	ReadStat(reader, Gameplay::Stat::Agility, "Agility");
	ReadStat(reader, Gameplay::Stat::Luck, "Luck");

	reader->NextClosing("Critter");
}

void Game::Critter::Init(ScriptCritter* script)
{
	_Script = script;
}

Game::ScriptCritter* Game::Critter::Self()
{
	return _Script;
}

Gameplay::Stat& Game::Critter::Stat()
{
	return _Stat;
}