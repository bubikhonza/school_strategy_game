#ifndef Desert_H
#define Desert_H

#include "tiles/tilebase.h"
#include "core/resourcemaps.h"
#include "core/myresourcemaps.h"
#include "graphics/simplemapitem.h"

namespace Game{
    class Desert;
}
/**
 * @brief The Desert class represents Desert in the gameworld.
 *
 * Desert has BasicProduction: \n
 * * Money = 3
 * * Food = 1
 * * Wood = 1
 * * Stone = 3
 * * Ore = 1
 *
 */
class Desert : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Desert() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the GameEventHandler.
     */
    Desert(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 3,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Game::DESERT_BP);
    /**
     * @brief Default destructor.
     */
    virtual ~Desert() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a new building-object to the tile. Building in desert adds
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

}; // class Desert


#endif // Desert_H
