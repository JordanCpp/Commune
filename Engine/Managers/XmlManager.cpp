#include "XmlManager.h"

using namespace Managers;

XmlManager::XmlManager(const std::string& StartPath):
	Manager(StartPath),
	_Reader("", Common::XmlReader::FromString)
{
}

XmlManager::~XmlManager()
{
    for (auto i = files.begin(); i != files.end(); i++)
    {
        delete i->second;
    }
}

Common::XmlFile* XmlManager::GetXmlFile(const std::string& DirName, const std::string& FileName)
{
    auto i = files.find(GetPath(DirName, FileName));

    Common::XmlFile* p = nullptr;

    if (i == files.end())
    {
        p = new Common::XmlFile(GetPath(DirName, FileName));
        files.emplace(GetPath(DirName, FileName), p);
    }
    else
    {
        p = i->second;
    }

    return p;
}

Common::XmlReader* XmlManager::GetReader(const std::string& DirName, const std::string& FileName)
{
    Common::XmlFile* p = GetXmlFile(DirName, FileName);

    _Reader.Reset(p->Content(), Common::XmlReader::FromString);

    return &_Reader;
}