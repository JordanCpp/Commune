#ifndef _Engine_Graphics_Image_h_
#define _Engine_Graphics_Image_h_

#include "Canvas.h"
#include <string>

namespace Arc
{
    namespace Graphics
    {
        class Image
        {
        public:
            Image(Canvas* Source, Color transparency, const std::string& Name);
            Image(Canvas* CanvasSource, SDL_Surface* SurfaceCanvas);
            ~Image();
            void Draw(Point Pt);
            void Draw(Point Pt, Point Sz);
            int Width();
            int Height();
        private:
            SDL_Surface* _Surface;
            SDL_Texture* _Texture;
            Canvas* _Canvas;
            int _Width;
            int _Height;
        };
    }
}

#endif