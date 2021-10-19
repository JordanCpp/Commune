#ifndef _Fallout_Formats_MsgFile_h_
#define _Fallout_Formats_MsgFile_h_

#include <string>
#include <unordered_map>

namespace Fallout
{
	namespace Formats
	{
		class MsgFile
		{
		public:
			MsgFile(const std::string& file);
			const std::string& String(int number);
		private:
			std::unordered_map<int, std::string> _Strings;
		};
	}
}

#endif