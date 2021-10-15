#ifndef _Engine_Graphics_Text_h_
#define _Engine_Graphics_Text_h_

#include <SDL2/SDL.h>
#include <string>
#include "Font.h"
#include "Image.h"

namespace Arc
{
    namespace Graphics
    {
        class Text
        {
        public:
            Text(Graphics::Canvas* CanvasSource, Graphics::Font* FontSource, const std::string& TextSource);
            ~Text();
            int Width();
            int Height();
            void Draw(Point Pt);
        private:
            Image* _Image;
        };
    }
}

#endif