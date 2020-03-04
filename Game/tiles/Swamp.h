    #ifndef Swamp_H
#define Swamp_H

#include "tiles/tilebase.h"
#include "core/resourcemaps.h"
#include "core/myresourcemaps.h"
#include "graphics/simplemapitem.h"

namespace Game{
    class Swamp;
}
/**
 * @brief The Swamp class represents Swamp in the gameworld.
 *
 * Swamp has BasicProduction: \n
 * * Money = 2
 * * Food = 1
 * * Wood = 2
 * * Stone = 3
 * * Ore = 3
 *
 */
class Swamp : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Swamp() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the GameEventHandler.
     */
    Swamp(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 3,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Game::SWAMP_BP);
    /**
     * @brief Default destructor.
     */
    virtual ~Swamp() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a new building-object to the tile. Building in Swamp adds
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

}; // class Swamp


#endif // Swamp_H
