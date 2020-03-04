#include "mine.h"


namespace Game {

Mine::Mine(const std::shared_ptr<iGameEventHandler>& eventhandler,
           const std::shared_ptr<iObjectManager>& objectmanager,
           const std::shared_ptr<PlayerBase>& owner,
           const int& tilespaces,
           const ResourceMap& buildcost,
           const ResourceMap& production
           ):
    BuildingBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        buildcost,
        production
        )
{
}

std::string Mine::getType() const
{
    return "Mine";
}


} // namespace Course
