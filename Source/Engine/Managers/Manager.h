#ifndef _Arcturus_Managers_Manager_h_
#define _Arcturus_Managers_Manager_h_

#include <string>

namespace Arc
{
	namespace Managers
	{
		class Manager
		{
		private:
			std::string _ShortPath;
			std::string _FullPath;
		public:
			Manager(const std::string& StartPath, size_t Count = 2048);
			const std::string& GetPath(const std::string DirName, const std::string& FileName);
		};
	}
}

#endif