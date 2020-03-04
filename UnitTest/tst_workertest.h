#ifndef WORKERTEST_H
#define WORKERTEST_H

#include <QtTest>
#include <../Game/core/gameeventhandler.h>
#include <../Game/core/objectmanager.h>
#include <../Game/core/player.h>
class WorkerTest : public QObject
{
    Q_OBJECT
public:
    WorkerTest();

private slots:
    void testGetType();
    void testCanBePlacedOnTile();
private:
    std::shared_ptr<ObjectManager> om;
    std::shared_ptr<GameEventHandler> eh;
};

#endif // WORKERTEST_H
