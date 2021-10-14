#ifndef _Common_Isometric_hpp_
#define _Common_Isometric_hpp_

#include "../Graphics/Point.h"

namespace Common
{
    class Isometric
    {
    public:
        Graphics::Point CartesianToIsometric(Graphics::Point pt);
        Graphics::Point IsometricToCartesian(Graphics::Point pt);
    private:

    };
}

#endif