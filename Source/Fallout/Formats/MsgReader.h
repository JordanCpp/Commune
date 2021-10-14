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
			MsgReader();
		private:
			std::fstream _Input;
		};
	}
}

#endif