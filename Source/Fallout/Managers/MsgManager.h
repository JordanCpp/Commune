#ifndef _Fallout_Managers_MsgManager_h_
#define _Fallout_Managers_MsgManager_h_

#include <unordered_map>
#include "../../Engine/Managers/Manager.h"
#include "../Formats/MsgFile.h"

namespace Fallout
{
    namespace Managers
    {
        class MsgManager
        {
        public:
            MsgManager(const std::string& path);
            Formats::MsgFile* Dialog(const std::string& file);
        private:
            Formats::MsgFile* Msg(const std::string& dir, const std::string& file);
            Arc::Managers::Manager _Manager;
            std::unordered_map<std::string, Formats::MsgFile*> _MsgFiles;
        };
    }
}

#endif