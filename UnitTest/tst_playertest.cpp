#include "tst_playertest.h"
#include "../Game/buildings/fortress.h"
#include "../Game/buildings/mine.h"
#include "../Game/tiles/mountains.h"

PlayerTest::PlayerTest()
{
}

void PlayerTest::testScore()
{
    std::shared_ptr<GameEventHandler> eh = std::make_shared<GameEventHandler>();
    std::shared_ptr<ObjectManager> om = std::make_shared<ObjectManager>();

    std::shared_ptr<Player> player = std::make_shared<Player>("test");
    std::shared_ptr<Game::Fortress> fortress = std::make_shared<Game::Fortress>(eh, om, player);
    std::shared_ptr<Game::Mine> sawmill = std::make_shared<Game::Mine>(eh, om, player);

    std::shared_ptr<Mountains> mountains = std::make_shared<Mountains>(Course::Coordinate(1, 1), eh, om);
    std::shared_ptr<Mountains> mountains2 = std::make_shared<Mountains>(Course::Coordinate(1, 2), eh, om);

    std::vector<std::shared_ptr<Course::TileBase>> tilesvec = {mountains, mountains2};

    om->addTiles(tilesvec);

    player->addObject(mountains);
    player->addObject(mountains2);

    mountains->addBuilding(fortress);
    mountains2->addBuilding(sawmill);

    player->addScore(3);
    player->removeScore(0.5);

    QVERIFY(player->getFinalScore() == 6.5);
}
