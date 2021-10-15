#ifndef _Arcturus_Graphics_Image_h_
#define _Arcturus_Graphics_Image_h_

#include "Canvas.h"
#include <string>
#include <vector>

namespace Arc
{
    namespace Graphics
    {
        class Image
        {
        public:
            Image(Canvas* Source, Color transparency, const std::string& Name);
            Image(Canvas* CanvasSource, SDL_Surface* SurfaceCanvas);
            Image(Canvas* canvas, Color transparency, size_t w, size_t h, const std::vector<Color>& data);
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