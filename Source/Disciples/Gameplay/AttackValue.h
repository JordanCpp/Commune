#ifndef _Disciples_Gameplay_AttackValue_h_
#define _Disciples_Gameplay_AttackValue_h_

#include "Source.h"

namespace Gameplay
{
	class AttackValue: public Source
	{
	public:
	private:
		size_t _Source;
		size_t _Chance;
		size_t _Damage;
	};
}

#endif