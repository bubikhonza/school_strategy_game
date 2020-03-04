#ifndef TST_MAPWINDOWTEST_H
#define TST_MAPWINDOWTEST_H
#include <QtTest>
#include <../Game/core/mapwindow.hh>
// add necessary includes here

class MapWindowTest : public QObject
{
    Q_OBJECT

public:
    MapWindowTest();
    ~MapWindowTest();

private slots:
    void testGetPlayersCount();

};
#endif // TST_MAPWINDOWTEST_H
