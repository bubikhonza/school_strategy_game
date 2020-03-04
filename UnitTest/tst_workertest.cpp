#include "tst_workertest.h"
#include <../Game/workers/aristocrat.h>
#include <../Game/workers/engineerworker.h>
#include <../Game/workers/leader.h>
#include <../Game/buildings/fortress.h>
#include <../Game/tiles/desert.h>


WorkerTest::WorkerTest()
{
    om = std::make_shared<ObjectManager>();
    eh = std::make_shared<GameEventHandler>();
}

void WorkerTest::testGetType()
{
    std::shared_ptr<Player> owner = std::make_shared<Player>("test");
    std::shared_ptr<Game::Aristocrat> ar = std::make_shared<Game::Aristocrat>(eh, om, owner);
    std::shared_ptr<Game::LeaderWorker> lw = std::make_shared<Game::LeaderWorker>(eh, om, owner);
    std::shared_ptr<Game::EngineerWorker> ew = std::make_shared<Game::EngineerWorker>(eh, om, owner);

    QVERIFY(ar->getType() == "Aristocrat");
    QVERIFY(lw->getType() == "LeaderWorker");
    QVERIFY(ew->getType() == "EngineerWorker");
}

void WorkerTest::testCanBePlacedOnTile()
{
    std::shared_ptr<Player> owner = std::make_shared<Player>("test");
    std::shared_ptr<Player> owner2 = std::make_shared<Player>("test2");

    std::shared_ptr<Desert> desert = std::make_shared<Desert>(Course::Coordinate(1, 3), eh, om);
    std::shared_ptr<Desert> desert2 = std::make_shared<Desert>(Course::Coordinate(1, 2), eh, om);

    std::shared_ptr<Game::EngineerWorker> ew = std::make_shared<Game::EngineerWorker>(eh, om, owner);
    std::shared_ptr<Game::EngineerWorker> ew2 = std::make_shared<Game::EngineerWorker>(eh, om, owner2);

    desert->setOwner(owner);
    desert2->setOwner(owner2);

    ew->setOwner(owner);
    ew2->setOwner(owner2);

    QVERIFY(ew->canBePlacedOnTile(std::dynamic_pointer_cast<TileBase>(desert)) == true);
    QVERIFY(ew2->canBePlacedOnTile(std::dynamic_pointer_cast<TileBase>(desert)) == false);
    QVERIFY(ew2->canBePlacedOnTile(std::dynamic_pointer_cast<TileBase>(desert2)) == true);
}

