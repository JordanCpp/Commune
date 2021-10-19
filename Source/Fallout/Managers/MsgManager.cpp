#include "MsgManager.h"

using namespace Fallout;

Managers::MsgManager::MsgManager(const std::string& path):
    _Manager(path.c_str())
{
}

Formats::MsgFile* Managers::MsgManager::Dialog(const std::string& file)
{
    return Msg("Text\\Dialog\\", file);
}

Formats::MsgFile* Managers::MsgManager::Msg(const std::string& dir, const std::string& file)
{
    auto i = _MsgFiles.find(_Manager.GetPath(dir, file));

    Formats::MsgFile* p = nullptr;

    if (i == _MsgFiles.end())
    {
        p = new Formats::MsgFile(_Manager.GetPath(dir, file));
        _MsgFiles.emplace(_Manager.GetPath(dir, file), p);
    }
    else
    {
        p = i->second;
    }

    return p;
}