#ifndef TILESTEST_H
#define TILESTEST_H
#include <../Game/core/gameeventhandler.h>
#include <../Game/core/objectmanager.h>
#include <../Game/core/player.h>
#include <QtTest>
class TilesTest : public QObject
{
    Q_OBJECT
public:
    TilesTest();
private:
    std::shared_ptr<ObjectManager> om;
    std::shared_ptr<GameEventHandler> eh;
private slots:
    void testGetType();
    void testAddBuilding();
};

#endif // WORKERTEST_H
