#include <QtTest>

#include "tst_objectmanagertest.h"
#include "tst_mapwindowtest.h"
#include "tst_workertest.h"
#include "tst_tilestest.h"
#include "tst_buildingstest.h"
#include "tst_playertest.h"
#include "tst_gameeventhandlertest.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

   int status = 0;
   auto ASSERT_TEST = [&status, argc, argv](QObject* obj) {
     status |= QTest::qExec(obj, argc, argv);
     delete obj;
   };

   ASSERT_TEST(new ObjectManagerTest());
   ASSERT_TEST(new MapWindowTest());
   ASSERT_TEST(new TilesTest());
   ASSERT_TEST(new WorkerTest());
   ASSERT_TEST(new BuildingsTest());
   ASSERT_TEST(new PlayerTest());
   ASSERT_TEST(new GameEventHandlerTest());



   return status;
}
