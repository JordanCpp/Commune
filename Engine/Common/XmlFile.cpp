#include "XmlFile.hpp"

using namespace Common;

XmlFile::XmlFile(const std::string & name)
{
    input.open(name.c_str());

    if (input.is_open())
    {
        input.seekg(0, std::ios::end);
        size_t size = (size_t)input.tellg();
        content.resize(size);
        input.seekg(0);
        input.read(&content[0], size);
    }
    else
    {
        std::cout << "Not found file: " + name << '\n';
        std::terminate();
    }
}

XmlFile::~XmlFile()
{
}

const std::string & XmlFile::Content()
{
    return content;
}