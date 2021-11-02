#include "Source/Disciples/Execute.h"
#include "Source/Fallout/Execute.h"
#include "Source/Arcanum/Execute.h"

int main(int argc, char* argv[])
{
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
		else if (strcmp(name, "Arcanum") == 0)
		{
			Arcanum::Execute arcanum("Arcanum.xml");
			arcanum.Run();
		}
		else
		{
			std::cout << "Not found Game!" << '\n';
		}
	}
	
	return 0;
}