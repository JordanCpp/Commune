#ifndef _Fallout_Game_Limits_h_
#define _Fallout_Game_Limits_h_

namespace Fallout
{
    namespace Limits
    {
        enum
        {
            MaxTiles = 300 * 300,
            MaxHexes = MaxTiles * 4,
            MaxCritters = 1024,
            MaxScripts = 4096
        };
    }
}

#endif