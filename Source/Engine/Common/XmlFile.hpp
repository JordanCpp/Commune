#ifndef _Arcturus_Common_XmlFile_hpp_
#define _Arcturus_Common_XmlFile_hpp_

#include <iostream>
#include <fstream>
#include <string>

namespace Arc
{
    namespace Common
    {
        class XmlFile
        {
        public:
            XmlFile(const std::string& name);
            ~XmlFile();
            const std::string& Content();
        private:
            std::fstream input;
            std::string content;
        };
    }
}

#endif