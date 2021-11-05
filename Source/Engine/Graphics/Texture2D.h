#ifndef _Arcturus_Graphics_Texture2D_h_
#define _Arcturus_Graphics_Texture2D_h_

#include <string>
#include "OpenGL.h"

namespace Arc
{
    namespace Graphics
    {
        class Texture2D
        {
        public:
            Texture2D(const std::string& path);
            ~Texture2D();
        private:
            GL::GLuint _Id;
            int _Width;
            int _Height;
            int _Channels;
            unsigned char* _Image;
        };
    }
}

#endif