#ifndef _Disciples_Gameplay_Immunity_h_
#define _Disciples_Gameplay_Immunity_h_

#include <array>

namespace Gameplay
{
	class Immunity
	{
	public:
		enum
		{
			Fire,
			Water,
			Earth,
			Limit
		};
		bool Get(size_t index);
		void On(size_t index);
		void Off(size_t index);
	private:
		std::array<bool, Immunity::Limit> _Value = { 0 };
	};
}

#endif