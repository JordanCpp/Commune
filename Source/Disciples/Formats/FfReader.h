#ifndef _Disciples_Formats_FfReader_h_
#define _Disciples_Formats_FfReader_h_

#include <vector>
#include <string>

namespace Formats
{
	struct FileInfo
	{
		size_t Id;
		size_t Size;
		size_t Offset;
		char Name[256];
	};

	class FfReader
	{
	public:
		void LoadFiles(const std::string& fileName);
		void Print()
		{
			for (size_t i = 0; i < _Files.size(); i++)
			{
				printf("%d:%d:%d:%s\n", _Files[i].Id, _Files[i].Size, _Files[i].Offset, _Files[i].Name);
			}
		}
	private:
		std::vector<FileInfo> _Files;
	};
}

#endif