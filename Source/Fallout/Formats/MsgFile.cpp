#include "MsgFile.h"
#include <fstream>
#include "MsgReader.h"

using namespace Fallout;
using namespace Formats;

MsgFile::MsgFile(const std::string& file)
{
	MsgReader msg(file);
	
	std::string text;

	while (msg.Next())
	{
		int number = std::stoi(msg.Content());
		
		msg.Next();
		msg.Next();
		text = msg.Content();

		_Strings.emplace(number, text);
	}
}

const std::string& MsgFile::String(int number)
{
	auto i = _Strings.find(number);

	return i->second;
}