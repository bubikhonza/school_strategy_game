 #include "gamescene.h"
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <math.h>
#include <core/gameobject.h>
#include <buildings/outpost.h>
#include "mapitem.h"
#include <QCoreApplication>

GameScene::GameScene(QWidget *qt_parent, int width, int height, int scale):Course::SimpleGameScene(qt_parent, width, height, scale)
{

}
bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos())){

            QPointF point = mouse_event->scenePos() / getScale();

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            QGraphicsItem* pressed = itemAt(point * getScale(), QTransform());

                qDebug() << "ObjID: " <<
                            static_cast<MapItem*>(pressed)
                            ->getBoundObject()->ID  << " pressed.";
                std::shared_ptr<Course::GameObject> go = static_cast<MapItem*>(pressed)->getBoundObject();
                emit signal_tile_clicked(go, pressed);
                return true;
        }
    }

    return false;
}

void GameScene::drawBuilding(std::shared_ptr<Course::GameObject> obj)
{
    MapItem* nItem = new MapItem(obj, getScale());
    addItem(nItem);
}

void GameScene::drawTile(std::shared_ptr<Course::GameObject> obj)
{
    MapItem* nItem = new MapItem(obj, getScale());
    addItem(nItem);
}

void GameScene::drawWorker(std::shared_ptr<Course::GameObject> obj)
{
    MapItem* nItem = new MapItem(obj, getScale());
    //nItem->x = obj->getCoordinate().x();
    //nItem->y = obj->getCoordinate().y();
    nItem->setCoordinates(obj->getCoordinate().x(), obj->getCoordinate().y());
    addItem(nItem);
}

void GameScene::removeWorker(QGraphicsItem *obj)
{
    QGraphicsScene::removeItem(obj);
}



