#ifndef _Arcturus_Managers_LanguageManager_h_
#define _Arcturus_Managers_LanguageManager_h_

#include "Manager.h"
#include "XmlManager.h"

namespace Arc
{
	namespace Managers
	{
		class LanguageManager : public Manager
		{
		public:
			LanguageManager(const std::string& StartPath, XmlManager* XmlManagerSource);
			void ActivateLang(const std::string& name);
			void ActivateFile(const std::string& name);
			const std::string& GetString(size_t number);
		private:
			XmlManager* _XmlManager;
			std::string _Lang;
			std::string _File;
			std::string _FullName;
			std::string _Error;
		};
	}
}

#endif