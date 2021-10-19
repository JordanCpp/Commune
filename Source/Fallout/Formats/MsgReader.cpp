#include "MsgReader.h"

using namespace Fallout;
using namespace Formats;

MsgReader::MsgReader(const std::string& file)
{
    _Input.open(file.c_str());

    _Tabs  = 1;
    _Lines = 0;
}

char MsgReader::NextChar()
{
    char ch = 0;

    _Input.get(ch);

    _Tabs++;

    if (ch == '\n')
    {
        _Tabs = 1;
        _Lines++;
    }

    return ch;
}

bool MsgReader::Eof()
{
    return _Input.eof();
}

bool MsgReader::Next()
{
    _Content.clear();

    char ch = NextChar();

    while (isspace(ch))
    {
        ch = NextChar();
    }

    while (ch == '#')
    {
        while (ch != '\n')
        {
            ch = NextChar();
        }

        ch = NextChar();
    }

    if (Eof())
    {
        return false;
    }

    if (ch == '{')
    {
        ch = NextChar();

        while (ch != '}')
        {
            _Content.push_back(ch);
            ch = NextChar();
        }

        return true;
    }

    return false;
}

const std::string& MsgReader::Content()
{
    return _Content;
}
