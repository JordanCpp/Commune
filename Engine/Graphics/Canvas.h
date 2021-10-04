#ifndef _Engine_Graphics_Canvas_h_
#define _Engine_Graphics_Canvas_h_

#include <SDL2/SDL.h>
#include "Point.h"
#include "Rect.h"
#include "Color.h"
#include <string>

namespace Graphics
{
    class Canvas
    {
    public:
        Canvas(Point Size, size_t Fps, const std::string& Title);
        ~Canvas();
        size_t Width();
        size_t Height();
        bool GetEvent(SDL_Event& Dest);
        void StopEvent();
        SDL_Renderer* Render();
        SDL_Window* Window();
        void FillRect(Rect& Rt, Color Cr);
        void DrawRect(Rect Rt, Color Cr);
        void DrawLine(Point first, Point last, Color color);
    private:
        bool _Running;
        SDL_Renderer* _Render;
        SDL_Window* _Window;
        size_t _Fps;
        Point _Size;
    };
}

#endif