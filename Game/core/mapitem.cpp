#include "mapitem.h"
#include <QDebug>
#include <core/player.h>
#include <core/mapwindow.hh>
#include "tiles/tilebase.h"


MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size):Course::SimpleMapItem(obj, size)
{
    myObject = obj;
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    objectType = myObject->getType();
    if(objectType=="Forest"){
        QImage image(":/images/forestPic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Swamp"){
        QImage image(":/images/swampPic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Desert"){
        QImage image(":/images/desertPic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Mountains"){
        QImage image(":/images/mountainsPic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Grassland"){
        QImage image(":/images/grasslandPic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Farm"){
        QImage image(":/images/farmPic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Mine"){
        QImage image(":/images/minePic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Fortress"){
        QImage image(":/images/fortressPic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Sawmill"){
        QImage image(":/images/sawmillPic.png");
        painter->drawImage(boundingRect(), image);
    }
    else if(objectType=="Outpost"){
        auto own = std::shared_ptr<Course::PlayerBase>(nullptr);
        if(myObject->getOwner() != nullptr){
            own = myObject->getOwner();
        } else{
            own = MapWindow::activePlayer;
        }
        if(own->getName() == "Player 1"){
            QImage image(":/images/outpostRed.png");
            painter->drawImage(boundingRect(), image);
        }
        else if(own->getName() == "Player 2"){
            QImage image(":/images/outpostWhite.png");
            painter->drawImage(boundingRect(), image);
        }
        else if(own->getName() == "Player 3"){
            QImage image(":/images/outpostBlack.png");
            painter->drawImage(boundingRect(), image);
        }
        else if(own->getName() == "Player 4"){
            QImage image(":/images/outpostPurple.png");
            painter->drawImage(boundingRect(), image);
        }

    }
    else if(objectType=="BasicWorker" || objectType=="EngineerWorker" || objectType == "LeaderWorker" || objectType=="Aristocrat"){
        std::shared_ptr<ObjectManager> om = std::dynamic_pointer_cast<ObjectManager>(MapWindow::m_objectManager);

        auto tile = om->getTile(Course::Coordinate(x, y));
        std::vector<std::shared_ptr<Course::WorkerBase>> workers = tile->getWorkers();

        QBrush *b = new QBrush();
        auto rectf = boundingRect();
        QSize size(11, 11);
        rectf.setX(rectf.x() - 5);
        rectf.setY(rectf.y() + 2);
        for(int i = 0; i < workers.size(); i++){
            if(workers.at(i)->getType() == "BasicWorker"){
                painter->setBrush(Qt::yellow);
                rectf.setX(rectf.x() + 7);
                rectf.setSize(size);
                painter->drawEllipse(rectf);
            }
            else if(workers.at(i)->getType() == "EngineerWorker"){
                painter->setBrush(Qt::gray);
                rectf.setX(rectf.x() + 7);
                rectf.setSize(size);
                painter->drawEllipse(rectf);
            }
            else if(workers.at(i)->getType() == "LeaderWorker"){
                painter->setBrush(Qt::green);
                rectf.setX(rectf.x() + 7);
                rectf.setSize(size);
                painter->drawEllipse(rectf);
            }
            else if(workers.at(i)->getType() == "Aristocrat"){
                painter->setBrush(Qt::cyan);
                rectf.setX(rectf.x() + 7);
                rectf.setSize(size);
                painter->drawRoundRect(rectf);
            }

        }

    }
    else if(objectType=="EngineerWorker"){
        Course::SimpleMapItem::paint(painter, option, widget);
    }

}

void MapItem::setCoordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}


