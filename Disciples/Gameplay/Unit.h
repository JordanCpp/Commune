#ifndef _Disciples_Gameplay_Unit_h_
#define _Disciples_Gameplay_Unit_h_

#include "Immunity.h"
#include "Ward.h"

class Unit
{
public:
private:
	Ward _Wards[8];
	Immunity _Immunities[8];
};

#endif