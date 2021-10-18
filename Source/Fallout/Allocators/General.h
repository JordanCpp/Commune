#ifndef _Fallout_Allocators_General_h_
#define _Fallout_Allocators_General_h_

#include <new>
#include <vector>
#include "../../Engine/Allocators/LinearAllocator.h"

extern Arc::Allocators::LinearAllocator* _General;

namespace Fallout
{
    namespace General
    {
        template <class T>
        struct General
        {
            typedef T value_type;

            General() = default;
            template <class U> constexpr General(const General <U>&) noexcept {}

            T* allocate(size_t bytes)
            {
                return (T*)_General->Alloc(bytes * sizeof(T));
            }

            void deallocate(T* p, size_t bytes) noexcept
            {
            }

        private:
        };

        template <class T, class U>
        bool operator==(const General <T>&, const General <U>&) { return true; }
        template <class T, class U>
        bool operator!=(const General <T>&, const General <U>&) { return false; }

        template <class T>
        using Vector = std::vector<T, General<T>>;

        using String = std::basic_string<General<char>>;
    }
}

#endif