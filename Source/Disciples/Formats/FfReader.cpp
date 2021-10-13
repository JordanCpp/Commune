#include "FfReader.h"
#include <cassert>

using namespace Formats;

void FfReader::LoadFiles(const std::string& fileName)
{
    FILE* file = fopen(fileName.c_str(), "rb");

    char Magic[5] = { 0 };

    assert(file != nullptr);

    fseek(file, 28, SEEK_SET);

    while (1)
    {
        FileInfo info = { 0 };
        fread(&Magic, 4, 1, file);

        if (feof(file)) break;

        fseek(file, 4, SEEK_CUR);
        fread(&info.Id, 4, 1, file);
        fread(&info.Size, 4, 1, file);
        fseek(file, 3 * 4, SEEK_CUR);
        info.Offset = ftell(file);

        fseek(file, info.Size, SEEK_CUR);

        _Files.push_back(info);
    }

    size_t offset = 0;

    for (size_t i = 0; i < _Files.size(); i++)
    {
        if (_Files[i].Id == 2)
        {
            offset = _Files[i].Offset;
            break;
        }
    }

    fseek(file, offset, SEEK_SET);

    size_t count = 0;

    fread(&count, 4, 1, file);

    for (size_t i = 0; i < count; i++)
    {
        char name[256] = { 0 };
        size_t id = 0;

        fread(&name, 256, 1, file);
        fread(&id, 4, 1, file);

        for (size_t j = 0; j < _Files.size(); j++)
        {
            if (_Files[j].Id == id)
            {
                memcpy(_Files[j].Name, name, sizeof(name));
                break;
            }
        }
    }

    fclose(file);
}