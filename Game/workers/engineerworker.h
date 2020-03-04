#ifndef EngineerWorker_H
#define EngineerWorker_H

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "core/myresourcemaps.h"

using namespace Course;
namespace Game {

/**
 * @brief The EngineerWorker class represents a "special worker" in the game.
 *
 * Worker has following production-efficiency: \n
 * * Money - 1.25 \n
 * * Food - 0.25 \n
 * * Wood - 0.25 \n
 * * Stone - 0.25 \n
 * * Ore - 1.00 \n
 *
 * EngineerWorkers consume Food and money. \n
 * * 20 money and 40 Food - Or EngineerWorker refuses to work. \n
 */
class EngineerWorker : public WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    EngineerWorker() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param descriptions contains descriptions and flavor texts.
     */
    EngineerWorker(const std::shared_ptr<iGameEventHandler>& eventhandler,
                   const std::shared_ptr<iObjectManager>& objectmanager,
                   const std::shared_ptr<PlayerBase>& owner,
                   const int& tilespaces = 1,
                   const ResourceMap& cost =
            Game::EW_RECRUITMENT_COST,
                   const ResourceMapDouble& efficiency =
            Game::EW_WORKER_EFFICIENCY
            );

    /**
     * @brief Default destructor.
     */
    virtual ~EngineerWorker() = default;

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
     * @post Exception guarantee: Basic
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
     * focus determine final multiplier that is based on WORKER_EFFICIENCY.
     *
     * @return
     */
    virtual const ResourceMapDouble tileWorkAction() override;

private:

}; // class EngineerWorker

} // namespace Data


#endif // EngineerWorker_H
