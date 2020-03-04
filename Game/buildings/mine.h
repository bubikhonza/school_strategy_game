#ifndef Mine_H
#define Mine_H

#include "buildings/buildingbase.h"
#include "core/myresourcemaps.h"


using namespace Course;
namespace Game {

/**
 * @brief The Mine class represents a Mine-building in the game.
 *
 * The Mine adds 2 base-production for food.
 */
class Mine : public BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Mine() = delete;

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
    explicit Mine(
            const std::shared_ptr<iGameEventHandler>& eventhandler,
            const std::shared_ptr<iObjectManager>& objectmanager,
            const std::shared_ptr<PlayerBase>& owner,
            const int& tilespaces = 1,
            const ResourceMap& buildcost = Game::MINE_BUILD_COST,
            const ResourceMap& production = Game::MINE_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Mine() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Mine

} // namespace Course


#endif // Mine_H
