#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mapwindow.hh"
#include "core/storydialog.h"
#include <core/gameeventhandler.h>
#include <core/objectmanager.h>
#include "core/worldgenerator.h"
#include "core/worldgenerator.cpp"
#include <tiles/forest.h>
#include <core/playerbase.h>
#include "player.h"
#include <QDebug>
#include <tiles/desert.h>
#include <tiles/mountains.h>
#include <tiles/Swamp.h>
#include <core/howtoplay.h>




MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("BK Game");
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_players2Btn_clicked()
{
   getDifficulty();
    Course::WorldGenerator& worldInstance = Course::WorldGenerator::getInstance();
    worldInstance.addConstructor<Course::Forest>(forest);
    worldInstance.addConstructor<Course::Grassland>(grassland);
    worldInstance.addConstructor<Desert>(desert);
    worldInstance.addConstructor<Mountains>(mountains);
    worldInstance.addConstructor<Swamp>(swamp);
    std::shared_ptr<Course::iObjectManager> objectManager(new ObjectManager());
    std::shared_ptr<Course::iGameEventHandler> gameEventHandler(new GameEventHandler());
    worldInstance.generateMap(5u, 5u, 3000u, objectManager, gameEventHandler);
    MapWindow* mapWindow = new MapWindow(2);
    mapWindow->show();
    mapWindow->setScale(70);
    mapWindow->setSize(5, 5);
    mapWindow->setObjectManager(objectManager);
    mapWindow->drawWorld(objectManager);
    this->hide();
    StoryDialog* st = new StoryDialog();
    st->show();

}
void MenuWindow::on_players3Btn_clicked()
{
    getDifficulty();
    Course::WorldGenerator& worldInstance = Course::WorldGenerator::getInstance();
    worldInstance.addConstructor<Course::Forest>(forest);
    worldInstance.addConstructor<Course::Grassland>(grassland);
    worldInstance.addConstructor<Desert>(desert);
    worldInstance.addConstructor<Mountains>(mountains);
    worldInstance.addConstructor<Swamp>(swamp);
    std::shared_ptr<Course::iObjectManager> objectManager(new ObjectManager());
    std::shared_ptr<Course::iGameEventHandler> gameEventHandler(new GameEventHandler());
    worldInstance.generateMap(9u, 9u, 3000u, objectManager, gameEventHandler);
    MapWindow* mapWindow = new MapWindow(3);
    mapWindow->show();
    mapWindow->setScale(70);
    mapWindow->setSize(9, 9);
    mapWindow->setObjectManager(objectManager);
    mapWindow->drawWorld(objectManager);
    this->hide();
    StoryDialog* st = new StoryDialog();
    st->show();

}


void MenuWindow::on_players4Btn_clicked()
{
    getDifficulty();
    Course::WorldGenerator& worldInstance = Course::WorldGenerator::getInstance();
    worldInstance.addConstructor<Course::Forest>(forest);
    worldInstance.addConstructor<Course::Grassland>(grassland);
    worldInstance.addConstructor<Desert>(desert);
    worldInstance.addConstructor<Mountains>(mountains);
    worldInstance.addConstructor<Swamp>(swamp);
    std::shared_ptr<Course::iObjectManager> objectManager(new ObjectManager());
    std::shared_ptr<Course::iGameEventHandler> gameEventHandler(new GameEventHandler());
    worldInstance.generateMap(12u, 12u, 3000u, objectManager, gameEventHandler);
    MapWindow* mapWindow = new MapWindow(4);
    mapWindow->show();
    mapWindow->setScale(70);
    mapWindow->setSize(12, 12);
    mapWindow->setObjectManager(objectManager);
    mapWindow->drawWorld(objectManager);
    this->hide();
    StoryDialog* st = new StoryDialog();
    st->show();
}

void MenuWindow::on_exitBtn_clicked()
{
    this->close();
}


void MenuWindow::on_howToPlayBtn_clicked()
{
    HowToPlay* how = new HowToPlay();
    how->show();
}

void MenuWindow::getDifficulty()
{
    if(ui->radioButton->isChecked()) //easy
    {
        forest =  3;
        grassland = 5;
        desert = 5;
        mountains =4;
        swamp = 1;

    }
    else if(ui->radioButton_2->isChecked()) //medium
    {
        forest =  3;
        grassland = 3;
        desert = 3;
        mountains =3;
        swamp = 3;

    }
    else if(ui->radioButton_3->isChecked()) //hard
    {
        forest =  1;
        grassland = 1;
        desert = 1;
        mountains =1;
        swamp = 5;

    }
}
