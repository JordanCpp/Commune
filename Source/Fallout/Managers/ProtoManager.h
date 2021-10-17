#ifndef _Fallout_Managers_ProtoManager_h_
#define _Fallout_Managers_ProtoManager_h_

#include "../../Engine/Managers/XmlManager.h"

namespace Fallout
{
    namespace Managers
    {
        class ProtoManager
        {
        public:
            ProtoManager(const std::string& path);
            Arc::Common::XmlReader* Proto(const std::string& dir, const std::string& file);
            Arc::Common::XmlReader* Critter(const std::string& file);
            Arc::Common::XmlReader* Parent(const std::string& file);
            Arc::Common::XmlReader* Tile(const std::string& file);
        private:
            Arc::Managers::XmlManager _XmlManagerBase;
            Arc::Managers::XmlManager _XmlManagerParent;
        };
    }
}

#endif