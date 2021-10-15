#ifndef _Arcturus_Common_ByteReader_hpp
#define _Arcturus_Common_ByteReader_hpp

#include <iostream>
#include <fstream>
#include <string>

namespace Arc
{
    namespace Common
    {
        class ByteReader
        {
        public:
            ByteReader(const std::string& name);
            ~ByteReader();
            bool Eof();
            uint8_t u8();
            uint16_t u16();
            uint32_t u32();
            int16_t i16();
            int32_t i32();
            void Pos(size_t value);
        private:
            std::fstream input;
        };
    }
}

#endif