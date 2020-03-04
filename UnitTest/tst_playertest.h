#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include <QtTest>
#include <../Game/core/gameeventhandler.h>
#include <../Game/core/objectmanager.h>
#include <../Game/core/player.h>
class PlayerTest : public QObject
{
    Q_OBJECT
public:
    PlayerTest();

private slots:
    void testScore();
};

#endif // PLAYERTEST_H
