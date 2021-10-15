#ifndef _Engine_Graphics_Point_h_
#define _Engine_Graphics_Point_h_

#include <cstdint>
#include "Point.h"

namespace Arc
{
    namespace Graphics
    {
        class Point
        {
        public:
            Point(size_t x, size_t y);
            ~Point();
            size_t PosX();
            size_t PosY();
            void PosX(size_t x);
            void PosY(size_t y);
        private:
            size_t _PosX;
            size_t _PosY;
        };
    }
}

#endif