#ifndef _Fallout_Game_Location_h_
#define _Fallout_Game_Location_h_

#include "../Managers/ObjectManager.h"
#include "../../Engine/Graphics/Camera.h"

namespace Fallout
{
    namespace Game
    {
        class Location
        {
        public:
            Location(Arc::Graphics::Camera* camera, Managers::ObjectManager* objectManager);
            size_t Size();
            int IndexToPosX(int t);
            int IndexToPosY(int t);
            int HexToPosX(int t);
            int HexToPosY(int t);
            void Hexes();
            void Tiles();
            void Draw();
        private:
            Arc::Graphics::Camera* _Camera;
            Managers::ObjectManager* _ObjectManager;
            std::array<Game::Tile*, Limits::MaxTiles> _Tiles;
            std::array<Game::Hex*, Limits::MaxHexes> _Hexes;
            size_t _Size;
        };
    }
}

#endif