#ifndef _Fallout_Allocators_System_h_
#define _Fallout_Allocators_System_h_

#include <new>
#include <vector>
#include "../../Engine/Allocators/LinearAllocator.h"

extern Arc::Allocators::LinearAllocator* _System;

namespace Fallout
{
    namespace System
    {
        template <class T>
        struct System
        {
            typedef T value_type;

            System() = default;
            template <class U> constexpr System(const System <U>&) noexcept {}

            T* allocate(size_t bytes) 
            {
                return (T*)_System->Alloc(bytes * sizeof(T));
            }

            void deallocate(T* p, size_t bytes) noexcept
            {
            }

        private:
        };

        template <class T, class U>
        bool operator==(const System <T>&, const System <U>&) { return true; }
        template <class T, class U>
        bool operator!=(const System <T>&, const System <U>&) { return false; }

        template <class T>
        using Vector = std::vector<T, System<T>>;

        using String = std::basic_string<System<char>>;
    }
}

#endif