#include <cassert>
#include "Source/Disciples/Execute.h"
#include "Source/Fallout/Execute.h"

int main(int argc, char* argv[])
{

	Fallout::Execute fallout("Fallout.xml");
	fallout.Run();

	/*
	char* name = nullptr;

	if (argc != 2)
	{
		std::cout << "Not found argument!" << '\n';
	}
	else
	{
		name = argv[1];

		if (strcmp(name, "Disciples") == 0)
		{
			Disciples::Execute disciples("Disciples.xml");
			disciples.Run();
		}
		else if (strcmp(name, "Fallout") == 0)
		{
			Fallout::Execute fallout("Fallout.xml");
			fallout.Run();
		}
		else
		{
			std::cout << "Not found Game!" << '\n';
		}
	}
	*/

	return 0;
}