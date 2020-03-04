#include <tst_objectmanagertest.h>
// add necessary includes here


ObjectManagerTest::ObjectManagerTest()
{
    eh = std::make_shared<GameEventHandler>();
    om = std::make_shared<ObjectManager>();
}

ObjectManagerTest::~ObjectManagerTest()
{

}

void ObjectManagerTest::testAddGetTiles()
{ 
    Desert* tile1 = new Desert(Course::Coordinate(1, 1), eh, om );
    Desert* tile2 = new Desert(Course::Coordinate(1, 2), eh, om );
    std::shared_ptr<Desert> t1(tile1);
    std::shared_ptr<Desert> t2(tile2);

    std::vector<std::shared_ptr<Course::TileBase>> vect{t1, t2};
    om->addTiles(vect);
    QVERIFY(om->getTile(Course::Coordinate(1, 1)) == t1);
    QVERIFY(om->getTile(t2->ID) == t2);

}

void ObjectManagerTest::testGetFreeTiles()
{
    QVERIFY(om->getNumberOfFreeTiles() == 2);
    auto tile = om->getTile(Course::Coordinate(1, 2));

    std::shared_ptr<Course::BuildingBase> b = std::make_shared<Course::BuildingBase>(eh, om, std::make_shared<Player>("test"));
    tile->addBuilding(b);
    QVERIFY(om->getNumberOfFreeTiles() == 1);
}

//#include "tst_objectmanagertest.moc"
