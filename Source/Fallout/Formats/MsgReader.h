#ifndef _Fallout_Formats_MsgReader_h_
#define _Fallout_Formats_MsgReader_h_

#include <fstream>

namespace Fallout
{
	namespace Formats
	{
		class MsgReader
		{
		public:
			MsgReader(const std::string& file);
			char NextChar();
			bool Eof();
			bool Next();
			const std::string& Content();
		private:
			size_t _Tabs;
			size_t _Lines;
			std::fstream _Input;
			std::string _Content;
		};
	}
}

#endif