#include "Swamp.h"


Swamp::Swamp(const Course::Coordinate &location,
             const std::shared_ptr<Course::iGameEventHandler> &eventhandler,
             const std::shared_ptr<Course::iObjectManager> &objectmanager,
             const unsigned int &max_build,
             const unsigned int &max_work,
             const Course::ResourceMap &production):Course::TileBase(location,
                                                                     eventhandler,
                                                                     objectmanager,
                                                                     max_build,
                                                                     max_work,
                                                                     production)
{


}
std::string Swamp::getType() const
{
    return "Swamp";
}
void Swamp::addBuilding(const std::shared_ptr<Course::BuildingBase>& building)
{
    TileBase::addBuilding(building);
    building->addHoldMarkers(1);
}
