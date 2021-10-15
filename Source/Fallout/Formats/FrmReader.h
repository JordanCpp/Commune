#ifndef _Fallout_Formats_FrmReader_h_
#define _Fallout_Formats_FrmReader_h_

#include <array>
#include <vector>
#include "../../Engine/Common/ByteReader.hpp"
#include "../../Engine/Graphics/Color.h"

namespace Fallout
{
	namespace Formats
	{
		struct FrmFrame
		{
			uint16_t width = 0;
			uint16_t height = 0;
			std::vector<Arc::Graphics::Color> pixels;
		};

		class FrmReader
		{
		public:
			enum
			{
				MaxDirs = 6
			};
			FrmReader(const std::string& file);
			size_t Dirs();
			size_t Frames();
			bool Next(FrmFrame& frame);
		private:
			Arc::Common::ByteReader _Reader;
			uint32_t _Version;
			uint16_t _FramesPerSecond;
			uint16_t _ActionFrame;
			uint16_t _FramesPerDirection;
			std::array<uint16_t, MaxDirs> _ShiftX;
			std::array<uint16_t, MaxDirs> _ShiftY;
			std::array<uint32_t, MaxDirs> _Offset;
			size_t _Dirs;
			size_t _CurrentFrame;
			size_t _CurrentDir;
		};
	}
}

#endif