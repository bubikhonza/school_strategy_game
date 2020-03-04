#include "tst_mapwindowtest.h"

MapWindowTest::MapWindowTest()
{

}

MapWindowTest::~MapWindowTest()
{

}

void MapWindowTest::testGetPlayersCount()
{
    MapWindow *m = new  MapWindow(5);
    QVERIFY(m->getPlayersVec().size() == 5);
}

//QTEST_MAIN(MapWindowTest)

//#include "tst_mapwindowtest.moc"
