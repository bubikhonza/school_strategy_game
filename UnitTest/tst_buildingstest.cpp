#include "tst_buildingstest.h"

BuildingsTest::BuildingsTest()
{

}
#include "tst_buildingstest.h"
#include <../Game/buildings/fortress.h>
#include <../Game/buildings/Sawmill.h>
#include <../Game/buildings/mine.h>

void BuildingsTest::testGetType()
{
    std::shared_ptr<ObjectManager> om = std::make_shared<ObjectManager>();
    std::shared_ptr<GameEventHandler> eh = std::make_shared<GameEventHandler>();
    std::shared_ptr<Player> p = std::make_shared<Player>("test");
    Game::Fortress *fortress = new Game::Fortress(eh, om, p);
    Game::Sawmill *sawmill = new Game::Sawmill(eh, om, p);
    Game::Mine *mine = new Game::Mine(eh, om, p);

    QVERIFY(fortress->getType() == "Fortress");
    QVERIFY(sawmill->getType() == "Sawmill");
    QVERIFY(mine->getType() == "Mine");
}

