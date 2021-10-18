#ifndef _Arcturus_Allocators_Allocator_hpp
#define _Arcturus_Allocators_Allocator_hpp

namespace Arc
{
	namespace Allocators
	{

		class Allocator
		{
		public:
			enum
			{
				Kb = 1024,
				Mb = Kb * 1024,
				Gb = Mb * 1024
			};

			virtual void* Alloc(size_t Count) = 0;
			virtual void Reset() = 0;
			virtual size_t FreeSize() = 0;
			virtual size_t UsedSize() = 0;
		private:
		};
	}
}

#endif