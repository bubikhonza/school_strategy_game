#include "tst_tilestest.h"
#include <../Game/tiles/desert.h>
#include <../Game/tiles/Swamp.h>
#include <../Game/tiles/mountains.h>
#include <../Game/buildings/fortress.h>



TilesTest::TilesTest()
{
    om = std::make_shared<ObjectManager>();
    eh = std::make_shared<GameEventHandler>();
}

void TilesTest::testGetType()
{
    std::shared_ptr<Desert> desert = std::make_shared<Desert>(Course::Coordinate(1, 1), eh, om);
    std::shared_ptr<Swamp> swamp = std::make_shared<Swamp>(Course::Coordinate(1, 2), eh, om);
    std::shared_ptr<Mountains> mountains = std::make_shared<Mountains>(Course::Coordinate(1, 3), eh, om);

    QVERIFY(desert->getType() == "Desert");
    QVERIFY(swamp->getType() == "Swamp");
    QVERIFY(mountains->getType() == "Mountains");
}

void TilesTest::testAddBuilding()
{
    std::shared_ptr<Desert> desert = std::make_shared<Desert>(Course::Coordinate(1, 1), eh, om);
    std::shared_ptr<Player> p = std::make_shared<Player>("test");
    p->addObject(desert);
    std::vector<std::shared_ptr<Course::TileBase>> v = {desert};
    om->addTiles(v);
    std::shared_ptr<Game::Fortress> f = std::make_shared<Game::Fortress>(eh, om, p);
    QVERIFY(desert->getBuildings().size() == 0);
    try {
        desert->addBuilding(f);
    } catch (std::exception e) {
        qDebug()<<e.what();
    }
    QVERIFY(desert->getBuildings().size() == 1);
}
