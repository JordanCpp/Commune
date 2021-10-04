#include "LanguageManager.h"
#include "../Common/XmlReader.hpp"

Managers::LanguageManager::LanguageManager(const std::string& StartPath, XmlManager* XmlManagerSource):
	Manager(StartPath),
	_XmlManager(XmlManagerSource)
{
}

void Managers::LanguageManager::ActivateLang(const std::string& name)
{
	_Lang = name;
}

void Managers::LanguageManager::ActivateFile(const std::string& name)
{
	_File = name;
}

const std::string& Managers::LanguageManager::GetString(size_t number)
{
	size_t Number = 0;

	_FullName.clear();
	_FullName.append(_File);
	_FullName.push_back('.');
	_FullName.append(_Lang);

	Common::XmlReader* reader = _XmlManager->GetReader("Text\\", _FullName);

	reader->Next();
	reader->AssertOpening("Text");

	while (reader->Next() && !reader->IsClosing("Text"))
	{
		if (reader->IsOpening("Message"))
		{
			reader->NextNode("Number");
			Number = reader->ValueInt();

			reader->NextNode("String");

			if (Number == number)
			{
				return reader->Value();
			}

			reader->NextClosing("Message");
		}
	}

	reader->AssertClosing("Text");

	_Error.append("Not found string: ");
	_Error.append(std::to_string(number));

	return _Error;
}