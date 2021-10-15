#ifndef _Arcturus_Common_XmlWriter_hpp
#define _Arcturus_Common_XmlWriter_hpp

#include <string>
#include <fstream>

namespace Arc
{
    namespace Common
    {
        class XmlWriter
        {
        public:
            XmlWriter(const std::string& Name);
            ~XmlWriter();
            void Node(const std::string& Name, const std::string& Value);
            void OpenTag(const std::string& Name);
            void CloseTag(const std::string& Name);
            void AddSpace();
        private:
            int mTabs;
            std::string mResult;
            std::ofstream mOutput;
        };
    }
}

#endif