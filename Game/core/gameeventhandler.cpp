#include "gameeventhandler.h"
#include "core/resourcemaps.h"
#include "core/basicresources.h"
#include <core/playerbase.h>
#include "player.h"

GameEventHandler::GameEventHandler()
{

}
bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{
    try {
        std::shared_ptr<Player> p1 = std::dynamic_pointer_cast<Player>(player);
        p1->myResourceMap.at(resource) = amount;

    } catch (std::exception e) {
        return false;
    }
    return true;
}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    try{
        std::shared_ptr<Player> p1 = std::dynamic_pointer_cast<Player>(player);
        p1->myResourceMap = resources;
    } catch (std::exception e) {
        return false;
    }
    return true;
}

