#ifndef _Arcturus_Managers_XmlManager_h_
#define _Arcturus_Managers_XmlManager_h_

#include "Manager.h"
#include <unordered_map>
#include "../Common/XmlFile.hpp"
#include "../Common/XmlReader.hpp"

namespace Arc
{
	namespace Managers
	{
		class XmlManager : public Manager
		{
		private:
			Common::XmlReader _Reader;
			std::unordered_map<std::string, Common::XmlFile*> files;
		public:
			XmlManager(const std::string& StartPath);
			~XmlManager();
			Common::XmlFile* GetXmlFile(const std::string& DirName, const std::string& FileName);
			Common::XmlReader* GetReader(const std::string& DirName, const std::string& FileName);
		};
	}
}

#endif