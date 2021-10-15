#ifndef _Arcturus_Graphics_Color_h_
#define _Arcturus_Graphics_Color_h_

#include <cstdint>

namespace Arc
{
    namespace Graphics
    {
        class Color
        {
        public:
            Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
            ~Color();
            uint8_t Red();
            uint8_t Green();
            uint8_t Blue();
            uint8_t Alpha();
        private:
            uint8_t _Red;
            uint8_t _Green;
            uint8_t _Blue;
            uint8_t _Alpha;
        };
    }
}

#endif