#include "mapwindow.hh"
#include "ui_mapwindow.h"
#include "buildings/outpost.h"
#include "buildings/farm.h"
#include "QLabel"
#include "core/resourcemaps.h"
#include "buildings/mine.h"
#include "buildings/Sawmill.h"
#include <tiles/forest.h>
#include <core/gameover.h>
#include <workers/basicworker.h>
#include "exceptions/illegalaction.h"
#include "exceptions/notenoughspace.h"
#include "exceptions/ownerconflict.h"
#include "buildings/fortress.h"
#include <QSound>
#include "interfaces/iobjectmanager.h"
#include "howtoplay.h"
#include <workers/leader.h>
#include <workers/engineerworker.h>
#include <workers/aristocrat.cpp>
#include <math.h>

std::shared_ptr<Course::iObjectManager> MapWindow::m_objectManager = std::shared_ptr<Course::iObjectManager>(nullptr);
std::shared_ptr<Player> MapWindow::activePlayer = std::shared_ptr<Player>(nullptr);


MapWindow::MapWindow(int playersNum, QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_simplescene(new GameScene(this))
{
    m_ui->setupUi(this);
    GameScene* sgs_rawptr = m_simplescene.get();
    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    createPlayers(playersNum);
    activePlayer = playersVec.at(0);

    this->setWindowTitle("BK Adventure!");

    QSound *s = new QSound(":/sounds/backgroundMusic.wav");
    s->setLoops(QSound::Infinite);
    s->play();

    connect( sgs_rawptr, &GameScene::signal_tile_clicked, this, &MapWindow::on_tile_clicked );
    //connect( sgs_rawptr, SIGNAL(signal_test()), this, SLOT(slot_test()));
    //connect( m_simplescene, SIGNAL(signal_tile_clicked(std::shared_ptr<Course::GameObject)), this, SLOT(on_tile_clicked(std::shared_ptr<Course::GameObject)));
}

void MapWindow::createPlayers(int num){
    for(int i = 0; i < num; i++){
        std::shared_ptr<Player> p(new Player("Player " + std::to_string(i+1)));
        playersVec.push_back(p);
    }
}

MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setGEHandler(
        std::shared_ptr<Course::iGameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}

void MapWindow::setObjectManager(std::shared_ptr<Course::iObjectManager> objectManager)
{
    m_objectManager = objectManager;
}

void MapWindow::setSize(int width, int height)
{
    m_simplescene->setSize(width, height);
}

void MapWindow::setScale(int scale)
{
    m_simplescene->setScale(scale);
}

void MapWindow::resize()
{
    m_simplescene->resize();
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->updateItem(obj);
}

void MapWindow::drawWorld(std::shared_ptr<Course::iObjectManager> om)
{
    std::shared_ptr<ObjectManager> objectManager = std::dynamic_pointer_cast<ObjectManager>(om);
    foreach (std::shared_ptr<Course::TileBase> tile, objectManager->getAllTiles()) {
        drawTile(tile);
    }
}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->drawItem(obj);
}

void MapWindow::drawBuilding( std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->drawBuilding(obj);


    //this->setWindowState(Qt::WindowState::WindowMinimized);
    //this->setWindowState(Qt::WindowState::WindowActive);
}

void MapWindow::drawTile(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->drawTile(obj);

}

void MapWindow::drawWorker(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->drawWorker(obj);
}

void MapWindow::on_endTurnBtn_clicked()
{
    int x = activePlayer->getFinalScore();
    qDebug() << "SCORE:" << x;
    auto curr_pos = std::find(playersVec.begin(), playersVec.end(), activePlayer) - playersVec.begin();
    foreach(auto pair, activePlayer->myResourceMap) {
        auto key = pair.first;
        auto value = pair.second;
        activePlayer->myResourceMap.at(key) +=  20;
    }


    try {
        wageWorkersAndIncome();
    } catch (std::exception e) {

    }

    try {
        activePlayer = playersVec.at(curr_pos + 1);
    } catch (std::exception e) {
        activePlayer = playersVec.at(0);
        roundNumber++;
    }
    m_ui->roundLabel->setText(QString::number(roundNumber));
    m_ui->playerNameLabel->setText(QString::fromStdString(activePlayer->getName()));
    selectedWorker = WorkerType::NON;
    selectedBuilding = BuildingsType::NONE;
    displayResourceLabels();
}


void MapWindow::on_tile_clicked(std::shared_ptr<Course::GameObject> go, QGraphicsItem* mapitem)

{
    try {
        //--------------------------CREATING OBJECTS-----------------------
        std::shared_ptr<Course::BuildingBase>building = std::shared_ptr<Course::BuildingBase>(nullptr);
        std::shared_ptr<Course::WorkerBase>worker = std::shared_ptr<Course::WorkerBase>(nullptr);
        if (selectedBuilding == BuildingsType::OUTPOST)
        {
            Course::Outpost *out = new Course::Outpost(m_GEHandler,m_objectManager, activePlayer);
            building.reset(out);
            buildBuilding(building,go);

        }
        else if(selectedBuilding == BuildingsType::FARM)
        {
            Course::Farm *out = new Course::Farm(m_GEHandler,m_objectManager, activePlayer);
            building.reset(out);
            buildBuilding(building,go);

        }
        else if(selectedBuilding == BuildingsType::MINE)
        {
            Game::Mine *out = new Game::Mine(m_GEHandler,m_objectManager, activePlayer);
            building.reset(out);
            buildBuilding(building,go);

        }
        else if(selectedBuilding == BuildingsType::FORTRESS)
        {
            Game::Fortress *out = new Game::Fortress(m_GEHandler,m_objectManager, activePlayer);
            building.reset(out);
            buildBuilding(building,go);
            activePlayer->increaseMaxLeaders();

        }
        else if(selectedBuilding == BuildingsType::SAWMILL)
        {
            Game::Sawmill *out = new Game::Sawmill(m_GEHandler,m_objectManager, activePlayer);
            building.reset(out);
            buildBuilding(building,go);

        }
        else if(selectedWorker == WorkerType::BASIC_WORKER)
        {
            Course::BasicWorker *out = new Course::BasicWorker(m_GEHandler,m_objectManager, activePlayer);
            worker.reset(out);
            setWorker(worker, go);
        }
        else if(selectedWorker == WorkerType::LEADER)
        {
            Game::LeaderWorker *out = new Game::LeaderWorker(m_GEHandler,m_objectManager, activePlayer);
            worker.reset(out);
            setWorker(worker, go);
            activePlayer->setLeadersNum(1);
        }
        else if(selectedWorker == WorkerType::ARISTOCRAT)
        {
            Game::Aristocrat *out = new Game::Aristocrat(m_GEHandler,m_objectManager, activePlayer);
            worker.reset(out);
            setWorker(worker, go);
        }
        else if(selectedWorker == WorkerType::ENGINEEER_WORKER)
        {
            Game::EngineerWorker *out = new Game::EngineerWorker(m_GEHandler,m_objectManager, activePlayer);
            worker.reset(out);
            setWorker(worker, go);
        }
        else if(selectedWorker == WorkerType::REMOVE_WORKER)
        {
            removeWorker(go, mapitem);
        }
        else
        {
            return;
        }
        // SETS TO empty
        selectedWorker = WorkerType::NON;
        selectedBuilding = BuildingsType::NONE;
        m_ui->chosenLbl->setText("Nothing");
        displayResourceLabels();
        //---------------------------ENDING GAME----------------------------
        std::shared_ptr<ObjectManager> om = std::dynamic_pointer_cast<ObjectManager>(m_objectManager);
        qDebug() << om->getNumberOfFreeTiles();
        if(om->getNumberOfFreeTiles() < 1){
            //lastRound = true;
            endGame();
        }
    } catch (Course::IllegalAction e) {
        selectedWorker = WorkerType::NON;
        selectedBuilding = BuildingsType::NONE;
        //m_ui->chosenLbl->setText(QString::fromStdString(e.what()));
        return;
    }
}
void MapWindow::on_outpostBtn_clicked()
{
    selectedBuilding = BuildingsType::OUTPOST;
    m_ui->chosenLbl->setText("Outpost");
    selectedWorker = WorkerType::NON;
}

void MapWindow::on_sawmillBtn_clicked()
{
    selectedBuilding = BuildingsType::SAWMILL;
    m_ui->chosenLbl->setText("Sawmill");
    selectedWorker = WorkerType::NON;
}

void MapWindow::on_farmBtn_clicked()
{
    selectedBuilding = BuildingsType::FARM;
    m_ui->chosenLbl->setText("Farm");
    selectedWorker = WorkerType::NON;
}

void MapWindow::on_mineBtn_clicked()
{
    selectedBuilding = BuildingsType::MINE;
    m_ui->chosenLbl->setText("Mine");
    selectedWorker = WorkerType::NON;
}

void MapWindow::on_fortressBtn_clicked()
{
    selectedBuilding = BuildingsType::FORTRESS;
    m_ui->chosenLbl->setText("Fortress");
    selectedWorker = WorkerType::NON;
}

std::vector<std::shared_ptr<Player> > MapWindow::getPlayersVec()
{
    return playersVec;
}

void MapWindow::on_cancelBuildingsBtn_clicked()
{
    selectedBuilding = BuildingsType::NONE;
    selectedWorker = WorkerType::NON;
    m_ui->chosenLbl->setText("Nothing");
}

void MapWindow::endGame()
{
    std::map<std::shared_ptr<Player>, double> scores;
    foreach(auto player, playersVec){
        scores.insert(std::pair<std::shared_ptr<Player>, double>(player, player->getFinalScore()));
    }
    double max = 0;
    std::shared_ptr<Player> maxP = std::make_shared<Player>("");
    foreach(auto m, scores){
        if(max < m.second)
        {
            max = m.second;
            maxP =m.first;
        }
    }

    GameOver* g = new GameOver(QString::fromStdString(maxP->getName()), max);
    this->setEnabled(false);

    g->show();


}

bool MapWindow::canPlaceBuilding(std::string type, std::shared_ptr<Course::TileBase> tile)
{
    std::vector<std::shared_ptr<BuildingBase>> buildings = tile->getBuildings();
    if(buildings.size()>=2){
        return false;
    }
    foreach(auto b, buildings){
        if(b->getType()==type){
            return false;
        }
        if(type != "Outpost" && b->getType()=="OutPost"){
            return true;
        }
    }
    if(buildings.size() == 0 && type=="Outpost"){
        return true;
    }
    if(buildings.size() != 0 && type!="Outpost"){
        return true;
    }
    return false;
}

bool MapWindow::canPlaceWorker(std::string type, std::shared_ptr<Course::TileBase> tile)
{
    std::vector<std::shared_ptr<BuildingBase>> buildings = tile->getBuildings();
    if(buildings.size()>1){
        return true;
    }
    return false;
}

bool MapWindow::canRemoveWorker(std::string type, std::shared_ptr<Course::TileBase> tile)
{
    if(!(tile->getOwner() == activePlayer)){
        throw IllegalAction("cant do that");
    }
    std::vector<std::shared_ptr<WorkerBase>> workers = tile->getWorkers();
    if(workers.size()>0){
        return true;
    }
    return false;
}

void MapWindow::displayResourceLabels()
{
    m_ui->moneyLbl->setText(QString::number(activePlayer->myResourceMap.at(Course::MONEY)));
    m_ui->foodLbl->setText(QString::number(activePlayer->myResourceMap.at(Course::FOOD)));
    m_ui->woodLbl->setText(QString::number(activePlayer->myResourceMap.at(Course::WOOD)));
    m_ui->stoneLbl->setText(QString::number(activePlayer->myResourceMap.at(Course::STONE)));
    m_ui->oreLbl->setText(QString::number(activePlayer->myResourceMap.at(Course::ORE)));
}

void MapWindow::wageWorkersAndIncome()
{
    foreach (auto obj, activePlayer->getObjects())
    {
        std::shared_ptr<Course::TileBase> tile = std::dynamic_pointer_cast<Course::TileBase>(obj);
        ResourceMapDouble EFFICIENCY = {
            {MONEY, 0.00},
            {FOOD, 0.00},
            {WOOD, 0.00},
            {STONE, 0.00},
            {ORE, 0.00}
        };
        int leader = 0;
        foreach(auto worker, tile->getWorkers())
        {

            foreach(auto pair, worker->RECRUITMENT_COST) {
                auto key = pair.first;
                auto value = pair.second;
                if(activePlayer->myResourceMap.at(key) - worker->RECRUITMENT_COST.at(key) < 0)
                {
                    m_ui->chosenLbl->setText("Some workers refused to work");
                    addIncome(tile,EFFICIENCY);
                    throw Course::IllegalAction("Worker deserves wage!");
                }
            }


            foreach(auto pair, worker->RECRUITMENT_COST) {
                auto key = pair.first;
                auto value = pair.second;
                activePlayer->myResourceMap.at(key) = activePlayer->myResourceMap.at(key) - worker->RECRUITMENT_COST.at(key);
            }
            if(worker->getType() == "Aristocrat")
            {
                activePlayer->addScore(0.1);
                continue;
            }
            if(worker->getType() == "LeaderWorker")
            {
                leader++;
                continue;
            }
            foreach(auto pair, worker->RECRUITMENT_COST) {
                auto key = pair.first;
                auto value = pair.second;
                EFFICIENCY.at(key) = worker->WORKER_EFFICIENCY.at(key) + EFFICIENCY.at(key);
            }

        }
        if(leader > 0)
        {
            foreach(auto pair, activePlayer->myResourceMap) {
                auto key = pair.first;
                auto value = pair.second;
                EFFICIENCY.at(key) = EFFICIENCY.at(key) * 2.5 * leader ;
            }
        }
        addIncome(tile, EFFICIENCY);
    }
}

void MapWindow::addIncome(std::shared_ptr<TileBase> tile, ResourceMapDouble EFFICIENCY)
{
    foreach(auto building, tile->getBuildings())
    {
        if(building->getType() != "Outpost")
        {

            foreach(auto pair, building->PRODUCTION_EFFECT) {
                auto key = pair.first;
                auto value = pair.second;
                activePlayer->myResourceMap.at(key) = activePlayer->myResourceMap.at(key) + int((building->PRODUCTION_EFFECT.at(key) * 3 * EFFICIENCY.at(key)* tile->BASE_PRODUCTION.at(key)));
            }
        }
    }

}


void MapWindow::buildBuilding(std::shared_ptr<Course::BuildingBase>building, std::shared_ptr<Course::GameObject> go )
{
    foreach(auto pair, building->BUILD_COST) {
        auto key = pair.first;
        auto value = pair.second;
        if(activePlayer->myResourceMap.at(key) - building->BUILD_COST.at(key) < 0)
        {
            m_ui->chosenLbl->setText("Not enought recourses!");
            selectedBuilding = BuildingsType::NONE;
            throw Course::IllegalAction("cant place building here!");
        }
    }
    //draw and add buildings
    building->setCoordinate(go->getCoordinate());
    auto tile = m_objectManager->getTile(building->getCoordinate());
    if(!canPlaceBuilding(building->getType(), tile)){
        throw Course::IllegalAction("cant place building here!");
    }
    tile->addBuilding(building);
    tile->setOwner(activePlayer);
    if(building->getType() == "Outpost")
        activePlayer->addObject(tile);
    this->drawBuilding(building);
    //music
    QSound* sound = new QSound(":/sounds/buildSound.wav");
    sound->play();
    //calculate
    foreach(auto pair, building->BUILD_COST) {
        auto key = pair.first;
        auto value = pair.second;
        activePlayer->myResourceMap.at(key) = activePlayer->myResourceMap.at(key) - building->BUILD_COST.at(key);
    }
}
void MapWindow::setWorker(std::shared_ptr<WorkerBase> worker, std::shared_ptr<GameObject> go)
{
    worker->setCoordinate(go->getCoordinate());
    auto tileW = m_objectManager->getTile(worker->getCoordinate());
    if(!canPlaceWorker(worker->getType(),tileW))
        throw Course::IllegalAction("Can't be placed here");
    tileW->addWorker(worker);
    tileW->setOwner(activePlayer);
    this->drawWorker(worker);
}

void MapWindow::removeWorker(std::shared_ptr<GameObject> go, QGraphicsItem* mapitem)
{
    auto tile = m_objectManager->getTile(go->getCoordinate());
    if(!canRemoveWorker("", tile)){
        throw IllegalAction("cant place worker here");
    }
    m_simplescene->removeWorker(mapitem);
    std::shared_ptr<WorkerBase> worker = std::dynamic_pointer_cast<WorkerBase>(go);
    tile->removeWorker(worker);
    if(worker->getType() == "LeaderWorker")
        activePlayer->setLeadersNum(-1);
}

void MapWindow::on_pushButton_clicked()
{
    HowToPlay* h = new HowToPlay();
    h->show();

}

void MapWindow::on_engineerWorkerBtn_clicked()
{
    selectedWorker = WorkerType::ENGINEEER_WORKER;
    selectedBuilding = BuildingsType::NONE;
    m_ui->chosenLbl->setText("Engineer Worker");
}

void MapWindow::on_leaderBtn_clicked()
{
    if(activePlayer->getLeaderMax() == activePlayer->getLeadersNum())
    {
        selectedWorker = WorkerType::NON;
        selectedBuilding = BuildingsType::NONE;
        m_ui->chosenLbl->setText("Cannot have another leader!");
    }
    else
    {
        selectedWorker = WorkerType::LEADER;
        selectedBuilding = BuildingsType::NONE;
        m_ui->chosenLbl->setText("Leader");
    }
}

void MapWindow::on_aristocratBtn_clicked()
{
    selectedWorker = WorkerType::ARISTOCRAT;
    selectedBuilding = BuildingsType::NONE;
    m_ui->chosenLbl->setText("Aristocrat");
}

void MapWindow::on_removeWorkerBtn_clicked()
{
    selectedWorker = WorkerType::REMOVE_WORKER;
    selectedBuilding = BuildingsType::NONE;
    m_ui->chosenLbl->setText("Remove worker");

}
void MapWindow::on_basicWorkerBtn_clicked()
{
    selectedWorker = WorkerType::BASIC_WORKER;
    selectedBuilding = BuildingsType::NONE;
    m_ui->chosenLbl->setText("Basic Worker");
}
