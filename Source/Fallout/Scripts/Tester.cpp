#include "Tester.h"

using namespace Fallout;

void Game::Tester::Talk(UI::Dialog* dialog, size_t node)
{
	if (node == 1)
	{
		dialog->Reply("fgd");

		if (Self()->Stat().Get(Gameplay::Stat::Intelligence) >= 4)
		{
			dialog->Option("fgdfg", 5);
		}
	}

	if (node == 5)
	{
	}
}

void Game::Tester::MapEnter()
{
}