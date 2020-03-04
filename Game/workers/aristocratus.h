#ifndef ARISTOCRATUS_H
#define ARISTOCRATUS_H


#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "core/myresourcemaps.h"

using namespace Course;
namespace Game {

/**
 * @brief The EngineerWorker class represents a "normal worker" in the game.
 *
 * Worker has following production-efficiency: \n
 * * Money - 0.25 \n
 * * Food - 1.00 \n
 * * Wood - 0.75 \n
 * * Stone - 0.50 \n
 * * Ore - 0.50 \n
 *
 * EngineerWorkers consume Food and money. \n
 * * 1 Food - Or EngineerWorker refuses to work. \n
 * * 1 Money - Or EngineerWorker works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the worker is refusing work.
 */
class Aristocratus : public WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Aristocratus() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param descriptions contains descriptions and flavor texts.
     */
    Aristocratus(const std::shared_ptr<iGameEventHandler>& eventhandler,
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
    virtual ~Aristocratus() = default;

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

