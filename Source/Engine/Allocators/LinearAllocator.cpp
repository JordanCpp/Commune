#include "LinearAllocator.h"
#include <cassert>

using namespace Arc;
using namespace Allocators;

LinearAllocator::LinearAllocator(size_t Count, Allocator* allocator) :
	_Capacity(Count),
	_Pos(0),
	_Data(nullptr),
	_Allocator(allocator)
{
	if (_Allocator == nullptr)
	{
		_Data = new uint8_t[_Capacity];
	}
	else
	{
		_Data = (uint8_t*)_Allocator->Alloc(Count);
	}
}

LinearAllocator::~LinearAllocator()
{
	if (_Allocator == NULL)
	{
		delete[] _Data;
	}
}

void LinearAllocator::Reset()
{
	_Pos = 0;
}

void* LinearAllocator::Alloc(size_t Count)
{
	assert(_Pos + Count < _Capacity);

	_Pos += Count;

	uint8_t* p = &_Data[_Pos];

	return p;
}

size_t LinearAllocator::FreeSize()
{
	return _Capacity - _Pos;
}

size_t LinearAllocator::UsedSize()
{
	return _Pos;
}