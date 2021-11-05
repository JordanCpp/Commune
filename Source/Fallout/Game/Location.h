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
            int PosToTile(int x, int y);
            void Hexes();
            void Tiles();
            void Draw();
        private:
            Arc::Graphics::Camera* _Camera;
            Managers::ObjectManager* _ObjectManager;
            std::vector<Game::Tile*> _Tiles;
            std::vector<Game::Hex*> _Hexes;
            size_t _Size;
        };
    }
}

#endif