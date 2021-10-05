#include "Manager.h"

using namespace Managers;

Manager::Manager(const std::string& StartPath, size_t Count)
{
	_ShortPath.reserve(Count);
	_ShortPath = StartPath;
}

const std::string& Manager::GetPath(const std::string DirName, const std::string& FileName)
{
	_FullPath.clear();

	_FullPath.append(_ShortPath);
	_FullPath.append(DirName);
	_FullPath.append(FileName);

	return _FullPath;
}