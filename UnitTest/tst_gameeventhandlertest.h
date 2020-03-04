#ifndef GAMEEVENTHANDLERTEST_H
#define GAMEEVENTHANDLERTEST_H


#include <QtTest>
#include <../Game/core/objectmanager.h>
#include <../Game/tiles/desert.h>
#include <../Game/buildings/Sawmill.h>
#include <../Game/core/gameeventhandler.h>
#include <../Game/core/player.h>
// add necessary includes here

class GameEventHandlerTest : public QObject
{
Q_OBJECT

public:
    GameEventHandlerTest();
private:
    std::shared_ptr<GameEventHandler> eh;

private slots:
    void testModifyResources();
};


#endif // GAMEEVENTHANDLERTEST_H
