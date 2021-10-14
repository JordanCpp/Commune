#include <cassert>
#include "Source/Disciples/Execute.h"
#include "Source/Fallout/Execute.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Not found argument!" << '\n';
	}
	else
	{
		if (strcmp(argv[1], "Disciples") == 0)
		{
			Disciples::Execute disciples("Disciples.xml");
			disciples.Run();
		}
		else if (strcmp(argv[1], "Fallout") == 0)
		{
			Fallout::Execute fallout("Fallout.xml");
			fallout.Run();
		}
		else
		{
			std::cout << "Not found Game!" << '\n';
		}
	}

	return 0;
}