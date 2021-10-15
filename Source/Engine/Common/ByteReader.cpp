#include "ByteReader.hpp"

using namespace Arc;
using namespace Common;

#define HTONS(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))

#define HTONL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24)) 

ByteReader::ByteReader(const std::string & name)
{
  input.open(name.c_str(), std::ios::in | std::ios::binary);

  if (!input.is_open())
  {
    std::cout << "Not open File:" + name << std::endl;
    std::terminate();
  }
}

ByteReader::~ByteReader()
{
  input.close();
}

void ByteReader::Pos(size_t value)
{
  input.seekg(value, std::ios::beg);
}

bool ByteReader::Eof()
{
  return input.good();
}

uint8_t ByteReader::u8()
{
  uint8_t val;
  input.read((char*)&val, sizeof(uint8_t));

  return val;
}

uint16_t ByteReader::u16()
{
  uint16_t val;
  input.read((char*)&val, sizeof(uint16_t));

  return HTONS(val);
}

int16_t ByteReader::i16()
{
  int16_t val;
  input.read((char*)&val, sizeof(int16_t));

  return HTONS(val);
}

uint32_t ByteReader::u32()
{
  uint32_t val;
  input.read((char*)&val, sizeof(uint32_t));
    
  return HTONL(val);
}

int32_t ByteReader::i32()
{
  int32_t val;
  input.read((char*)&val, sizeof(int32_t));
    
  return HTONL(val);
}