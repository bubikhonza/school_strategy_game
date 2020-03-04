#ifndef BUILDINGSTEST_H
#define BUILDINGSTEST_H

#include <QtTest>
#include <../Game/core/gameeventhandler.h>
#include <../Game/core/objectmanager.h>
#include <../Game/core/player.h>
class BuildingsTest : public QObject
{
    Q_OBJECT
public:
    BuildingsTest();

private slots:
    void testGetType();
};

#endif // BUILDINGSTEST_H
