#include "tst_gameeventhandlertest.h"

GameEventHandlerTest::GameEventHandlerTest()
{
    eh = std::make_shared<GameEventHandler>();
}

void GameEventHandlerTest::testModifyResources()
{
    std::shared_ptr<Player> player = std::make_shared<Player>("test");
    eh->modifyResource(player, Course::FOOD, 300);
    QVERIFY(player->myResourceMap.at(Course::FOOD) == 300);
    ResourceMap custom = {
        {MONEY, 333},
        {FOOD, 333},
        {WOOD, 333},
        {STONE, 333},
        {ORE, 333},
    };
    eh->modifyResources(player, custom);
    QVERIFY(player->myResourceMap == custom);
}
