#ifndef _Arcturus_Graphics_Canvas3D_h_
#define _Arcturus_Graphics_Canvas3D_h_

#include <SDL2/SDL.h>
#include "Point.h"

namespace Arc
{
    namespace Graphics
    {
        class Canvas3D
        {
        public:
            Canvas3D(Arc::Graphics::Point size, size_t fps);
            ~Canvas3D();
            bool GetEvent(SDL_Event& Dest);
            size_t Width();
            size_t Height();
        private:
            Arc::Graphics::Point _Size;
            bool _Running;
            size_t _Fps;
            SDL_Window* _Window;
            SDL_GLContext _Context;
        };
    }
}

#endif