#include "Disciples/Disciples.h"
#include "Engine/GUI/Factory.h"
#include "Disciples/UI/UI.h"
#include "Disciples/UI/MainMenu.h"
#include "Disciples/UI/Editor.h"

struct IndexInfo 
{
	size_t Id;
	char Name[64];
};

struct AnimInfo
{
	size_t AnimNumber;
	size_t SeqNumber;
	char Name[64];
};

struct ImageInfo
{
	char Name[64];
};

class FrameInfo
{
public:
	void LoadIndex(const std::string& fileName)
	{
		FILE* index = fopen(fileName.c_str(), "rb");

		size_t count = 0;
		fread(&count, 4, 1, index);

		for (size_t i = 0; i < count; i++)
		{
			IndexInfo info = { 0 };

			fread(&info.Id, 4, 1, index);

			int ch = 0;
			size_t j = 0;

			ch = getc(index);

			while (ch)
			{
				info.Name[j++] = (char)ch;
				ch = getc(index);
			}

			_Indices.push_back(info);

			fseek(index, 8, SEEK_CUR);
		}

		fclose(index);
	}

	void LoadAnims(const std::string& fileName)
	{
		FILE* file = fopen(fileName.c_str(), "rb");

		size_t count = 0;

		fread(&count, 4, 1, file);

		AnimInfo info = { 0 };

		for (size_t i = 0; i < count; i++)
		{
			int ch = 0;
			size_t j = 0;

			ch = getc(file);

			while (ch)
			{
				info.Name[j++] = (char)ch;
				ch = getc(file);
			}

			_Anims.push_back(info);
		}

		fclose(file);
	}

	void LoadImages(const std::string& fileName)
	{
		FILE* file = fopen(fileName.c_str(), "rb");

		//for (size_t i = 0; i < _Indices.size(); i++)
		//{
			fseek(file, 0xB + 1024, SEEK_CUR);

			int FileFramesNumber = 0;
			fread(&FileFramesNumber, 4, 1, file);
			printf("%d\n", FileFramesNumber);
			for (int f = 0; f < FileFramesNumber; f++)
			{
				// - получим имя кадра из файла
				static char FrameName[256];

				int name_len = 0, ch = 0;
				do {
					ch = getc(file);
					FrameName[name_len++] = (char)ch;
				} while (ch);
				printf("Converting frame: %s\n", FrameName);
			}
		//}

		fclose(file);
	}

	void PrintI()
	{
		for (size_t i = 0; i < _Indices.size(); i++)
		{
			printf("Id=%d, Name=%s\n", _Indices[i].Id, _Indices[i].Name);
		}
	}

	void PrintA()
	{
		for (size_t i = 0; i < _Anims.size(); i++)
		{
			printf("Name=%s\n", _Anims[i].Name);
		}
	}
private:
	std::vector<IndexInfo> _Indices;
	std::vector<AnimInfo> _Anims;
};

int main(int argc, char* argv[])
{
	Disciples disciples("Files\\");
	disciples.Run();

	//FrameInfo info;

	//info.LoadIndex("d:\\DisNew\\Imgs\\BatItems\\-INDEX.OPT");
	//info.LoadAnims("d:\\DisNew\\Imgs\\BatItems\\-ANIMS.OPT");
	//info.LoadImages("d:\\DisNew\\Imgs\\BatItems\\-IMAGES.OPT");

	//info.PrintI();
	//info.PrintA();

	return 0;
}