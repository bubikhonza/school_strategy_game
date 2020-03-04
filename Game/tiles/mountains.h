#ifndef MOUNTAINS_H
#define MOUNTAINS_H

#include "tiles/tilebase.h"
#include "core/resourcemaps.h"
#include "core/myresourcemaps.h"
#include "graphics/simplemapitem.h"

namespace Game{
    class Mountains;
}
/**
 * @brief The Mountains class represents Mountains in the gameworld.
 *
 * Mountains has BasicProduction: \n
 * * Money = 1
 * * Food = 2
 * * Wood = 2
 * * Stone = 4
 * * Ore = 4
 *
 */
class Mountains : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Mountains() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the GameEventHandler.
     */
    Mountains(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 3,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Game::MOUNTAINS_BP);
    /**
     * @brief Default destructor.
     */
    virtual ~Mountains() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a new building-object to the tile. Building in Mountains adds
     * one hold-marker to the building.
     *
     * Phases: \n
     * 1. Check that there is space for the building. \n
     * 2. Call parent's addBuilding \n
     * 3. Add a HoldMarker for the building. \n
     *
     * @post Exception guarantee: Strong
     * @exception OwnerConflict - If the tile's ownership prevents placing the
     * \b building.
     * @exception NoSpace - If the tile doesn't have enough space for
     * the \b building.
     */
    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Mountains


#endif // Mountains_H
