#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <core/objectmanager.h>
#include <map>
#include "core/resourcemaps.h"
#include "interfaces/igameeventhandler.h"
#include "player.h"

#include <core/gamescene.h>
#include <core/mapitem.h>

#include "buildings/Sawmill.h"



namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum BuildingsType {
        NONE = 0,
        OUTPOST,
        FARM,
        FORTRESS,
        MINE,
        SAWMILL

    };
    enum WorkerType {
        NON = 0,
        BASIC_WORKER,
        ENGINEEER_WORKER,
        LEADER,
        ARISTOCRAT,
        REMOVE_WORKER

    };
    /**
     * @brief Explicit constructor.
     * @param parent QWidget
     * @param represents how many players are going to play
     * @param objects (optional) std::vector of shared-pointers to game handlers
     * @pre playersNum < 0
     */
    explicit MapWindow(int playersNum, QWidget *parent = 0,
                       std::shared_ptr<Course::iGameEventHandler> GEHandler = {}
                       );
    ~MapWindow();
    /**
     * @brief sets Handler to private variable m_GEHandler
     */
    void setGEHandler(std::shared_ptr<Course::iGameEventHandler> nHandler);
    /**
     * @brief sets object manager to private variable m_objectManager
     */
    void setObjectManager(std::shared_ptr<Course::iObjectManager> objectManager);
    /**
     * @brief sets dimensions of scene
     * @param width of scene
     * @param height of scene
     */
    void setSize(int width, int height);
    /**
     * @brief sets scale of scene
     * @param scale of scene
     */
    void setScale(int scale);
    /**
     * @brief call resize to the scene
     */
    void resize();

    /**
     * @brief draw item on scene
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief remove item from the scene
     */
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief update item on scene
     */
    void updateItem( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief Draw world in loop tile by tile
     */
    void drawWorld(std::shared_ptr<Course::iObjectManager> om);
    /**
     * @brief draw building
     */
    void drawBuilding( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief draw tile on scene
     */
    void drawTile( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief draw worker
     */
    void drawWorker( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief static variable
     * shared pointer to player
     */
    static std::shared_ptr<Player> activePlayer;
    /**
     * @brief static variable
     *  shared pointer to class implementing iObjectManager
     */
    static std::shared_ptr<Course::iObjectManager> m_objectManager;
    /**
     * @brief Returns vector of shared pointers to Player
     */
    std::vector<std::shared_ptr<Player>> getPlayersVec();



private slots:
    void on_endTurnBtn_clicked();
    void on_outpostBtn_clicked();
    void on_sawmillBtn_clicked();

    void on_farmBtn_clicked();

    void on_mineBtn_clicked();

    void on_cancelBuildingsBtn_clicked();

    void on_basicWorkerBtn_clicked();

    void on_fortressBtn_clicked();

    void on_pushButton_clicked();

    void on_engineerWorkerBtn_clicked();

    void on_leaderBtn_clicked();

    void on_aristocratBtn_clicked();

    void on_removeWorkerBtn_clicked();

public slots:
    void on_tile_clicked(std::shared_ptr<Course::GameObject> go, QGraphicsItem* mapitem);

private:
    void displayResourceLabels();
    void wageWorkersAndIncome();
    void addIncome(std::shared_ptr<Course::TileBase> tile, ResourceMapDouble EFFICIENCY);
    void buildBuilding(std::shared_ptr<Course::BuildingBase>building, std::shared_ptr<Course::GameObject> go);
    void setWorker(std::shared_ptr<Course::WorkerBase>worker, std::shared_ptr<Course::GameObject> go);
    void removeWorker(std::shared_ptr<Course::GameObject> go, QGraphicsItem* mapitem);
    Ui::MapWindow* m_ui;
    std::shared_ptr<Course::iGameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<GameScene> m_simplescene = nullptr;
    std::vector<std::shared_ptr<Player>> playersVec;
    void createPlayers(int num);
    BuildingsType selectedBuilding = NONE;
    WorkerType selectedWorker = NON;
    int roundNumber = 1;
    bool lastRound = false;
    void endGame();
    bool canPlaceBuilding(std::string type, std::shared_ptr<Course::TileBase> tile);
    bool canPlaceWorker(std::string type, std::shared_ptr<Course::TileBase> tile);
    bool canRemoveWorker(std::string type, std::shared_ptr<Course::TileBase> tile);
};
#endif // MapWINDOW_HH

