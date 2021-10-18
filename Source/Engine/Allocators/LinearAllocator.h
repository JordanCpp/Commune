#ifndef _Arc_Allocators_LinearAllocator_h_
#define _Arc_Allocators_LinearAllocator_h_

#include "Allocator.h"
#include <stdlib.h>
#include <cstdint>

namespace Arc
{
	namespace Allocators
	{
		class LinearAllocator : public Allocator
		{
		public:
			enum
			{
				Kb = 1024,
				Mb = Kb * 1024,
				Gb = Mb * 1024
			};

			LinearAllocator(size_t Count, Allocator* allocator = nullptr);
			~LinearAllocator();
			void Reset();
			void* Alloc(size_t Count);
			size_t FreeSize();
			size_t UsedSize();
		private:
			size_t _Capacity;
			size_t _Pos;
			uint8_t* _Data;
			Allocator* _Allocator;
		};
	}
}

#endif