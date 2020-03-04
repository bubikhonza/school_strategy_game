#ifndef ARISTOCRAT_H
#define ARISTOCRAT_H


#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "core/myresourcemaps.h"

using namespace Course;
namespace Game {

/**
 * @brief The Aristocrat represent "diplomat" in the game
 *
 * Aristocrat gives you points of influence which you need to win a game
 *
 * Aristocrats consume Food and money. \n
 * * 200 MONEY and 60 Food - Or Aristocrat refuses to work. \n
 */
class Aristocrat : public WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Aristocrat() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param descriptions contains descriptions and flavor texts.
     */
    Aristocrat(const std::shared_ptr<iGameEventHandler>& eventhandler,
                   const std::shared_ptr<iObjectManager>& objectmanager,
                   const std::shared_ptr<PlayerBase>& owner,
                   const int& tilespaces = 1,
                   const ResourceMap& cost =
            Game::ARISTOCRAT_RECRUITMENT_COST,
                   const ResourceMapDouble& efficiency =
            Game::ARISTOCRAT_WORKER_EFFICIENCY
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Aristocrat() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Check if the worker can be placed on the Tile according to
     * it's placement rule. Only rule is that the Tile must have same owner
     * as the worker.
     * @param target is the Tile that worker is being placed on.
     * @return
     * True - If baseclass' method return true and target Tile has space
     * for worker.
     * False - If both conditions aren't met.
     * @note Override to change placement rules for derived worker.
     */
    virtual bool canBePlacedOnTile(
            const std::shared_ptr<TileBase> &target) const override;

    /**
     * @brief Performs the Worker's default action.
     */
    virtual void doSpecialAction() override;

    /**
     * @brief Returns Worker's efficiency at resource production.
     * Worker consumes FOOD and MONEY. Resource consumption and resource
     *
     * @return
     */
    virtual const ResourceMapDouble tileWorkAction() override;

private:

}; // class Aristocrat

} // namespace Data


#endif // Aristocrat_H
