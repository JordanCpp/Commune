#ifndef _Disciples_Gameplay_Ward_h_
#define _Disciples_Gameplay_Ward_h_

#include <cstdint>
#include <array>

namespace Gameplay
{
	class Ward
	{
	public:
		enum
		{
			Limit
		};

		uint8_t Get(size_t index);
		void Set(size_t index, uint8_t value);
	private:
		std::array<uint8_t, Ward::Limit> _Value = { 0 };
	};
}

#endif