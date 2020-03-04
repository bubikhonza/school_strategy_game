#ifndef Fortress_H
#define Fortress_H

#include "buildings/buildingbase.h"
#include "core/myresourcemaps.h"


using namespace Course;
namespace Game {

/**
 * @brief The Fortress class represents a Fortress-building in the game.
 *
 * Increase number of leaders by one for each builded fortress
 */
class Fortress : public BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Fortress() = delete;

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
    explicit Fortress(
            const std::shared_ptr<iGameEventHandler>& eventhandler,
            const std::shared_ptr<iObjectManager>& objectmanager,
            const std::shared_ptr<PlayerBase>& owner,
            const int& tilespaces = 1,
            const ResourceMap& buildcost = Game::FORTRESS_BUILD_COST,
            const ResourceMap& production = Game::FORTRESS_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Fortress() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Fortress

} // namespace Course


#endif // Fortress_H
