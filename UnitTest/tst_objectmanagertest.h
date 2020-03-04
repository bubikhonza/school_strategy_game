#ifndef OBJECTMANAGERTEST_H
#define OBJECTMANAGERTEST_H

#include <QtTest>
#include <../Game/core/objectmanager.h>
#include <../Game/tiles/desert.h>
#include <../Game/buildings/Sawmill.h>
#include <../Game/core/gameeventhandler.h>
#include <../Game/core/player.h>
// add necessary includes here

class ObjectManagerTest : public QObject
{
Q_OBJECT

public:
    ObjectManagerTest();
    ~ObjectManagerTest();
private:
    std::shared_ptr<ObjectManager> om;
    std::shared_ptr<GameEventHandler> eh;

private slots:
    void testAddGetTiles();
    void testGetFreeTiles();
};

#endif // OBJECTMANAGERTEST_H
