#ifndef _Disciples_Gameplay_Attack_h_
#define _Disciples_Gameplay_Attack_h_

#include "AttackValue.h"

namespace Gameplay
{
	class Attack
	{
	public:
		AttackValue& Base();
		AttackValue& Effect();
	private:
		AttackValue _Base;
		AttackValue _Effect;
	};
}

#endif