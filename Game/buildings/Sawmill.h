#ifndef Sawmill_H
#define Sawmill_H

#include "buildings/buildingbase.h"
#include "core/myresourcemaps.h"


using namespace Course;
namespace Game {

/**
 * @brief The Sawmill class represents a Sawmill-building in the game.
 *
 * The Sawmill adds 2 base-production for food.
 */
class Sawmill : public BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Sawmill() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param tile points to the tile upon which the building is constructed.
     *
     * @post Exception Guarantee: No guarantee.
     * @exception OwnerConflict - if the building conflicts with tile's
     * ownership.
     */
    explicit Sawmill(
            const std::shared_ptr<iGameEventHandler>& eventhandler,
            const std::shared_ptr<iObjectManager>& objectmanager,
            const std::shared_ptr<PlayerBase>& owner,
            const int& tilespaces = 1,
            const ResourceMap& buildcost = Game::SAWMILL_BUILD_COST,
            const ResourceMap& production = Game::SAWMILL_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Sawmill() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Sawmill

} // namespace Course


#endif // Sawmill_H
