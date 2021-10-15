#ifndef _Arcturus_Graphics_Rect_h_
#define _Arcturus_Graphics_Rect_h_

#include <cstdint>
#include "Point.h"

namespace Arc
{
    namespace Graphics
    {
        class Rect
        {
        public:
            Rect(size_t x, size_t y, size_t w, size_t h);
            Rect(Point pos, Point size);
            Rect();
            bool Contains(Point Pt);
            size_t PosX();
            size_t PosY();
            size_t Width();
            size_t Height();
            void PosX(size_t value);
            void PosY(size_t value);
            void Width(size_t value);
            void Height(size_t value);

        private:
            size_t _PosX;
            size_t _PosY;
            size_t _Width;
            size_t _Height;
        };
    }
}

#endif