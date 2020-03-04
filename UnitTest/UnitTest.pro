QT += testlib core gui widgets multimedia

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_mapwindowtest.cpp \
    ../Game/buildings/fortress.cpp \
    ../Game/buildings/mine.cpp \
    ../Game/buildings/sawmill.cpp \
    ../Game/core/gameeventhandler.cpp \
    ../Game/core/gameover.cpp \
    ../Game/core/gamescene.cpp \
    ../Game/core/howtoplay.cpp \
    ../Game/core/mapitem.cpp \
    ../Game/core/mapwindow.cc \
    ../Game/core/menuwindow.cpp \
    ../Game/core/objectmanager.cpp \
    ../Game/core/player.cpp \
    ../Game/core/storydialog.cpp \
    ../Game/tiles/desert.cpp \
    ../Game/tiles/mountains.cpp \
    ../Game/tiles/swamp.cpp \
    ../Game/workers/engineerworker.cpp \
    ../Game/workers/leader.cpp \
    tst_buildingstest.cpp \
    tst_gameeventhandlertest.cpp \
    tst_main.cpp \
    tst_objectmanagertest.cpp \
    tst_playertest.cpp \
    tst_tilestest.cpp \
    tst_workertest.cpp

INCLUDEPATH += \
    $$PWD/../Course/CourseLib \
    $$PWD/../Game \

HEADERS += \
    ../Game/buildings/Sawmill.h \
    ../Game/buildings/fortress.h \
    ../Game/buildings/mine.h \
    ../Game/core/gameeventhandler.h \
    ../Game/core/gameover.h \
    ../Game/core/gamescene.h \
    ../Game/core/howtoplay.h \
    ../Game/core/mapitem.h \
    ../Game/core/mapwindow.hh \
    ../Game/core/menuwindow.h \
    ../Game/core/myresourcemaps.h \
    ../Game/core/objectmanager.h \
    ../Game/core/player.h \
    ../Game/core/storydialog.h \
    ../Game/tiles/Swamp.h \
    ../Game/tiles/desert.h \
    ../Game/tiles/mountains.h \
    ../Game/workers/engineerworker.h \
    ../Game/workers/leader.h \
    tst_buildingstest.h \
    tst_gameeventhandlertest.h \
    tst_mapwindowtest.h \
    tst_objectmanagertest.h \
    tst_playertest.h \
    tst_tilestest.h \
    tst_workertest.h

FORMS += \
    ../Game/gameover.ui \
    ../Game/howtoplay.ui \
    ../Game/mapwindow.ui \
    ../Game/menuwindow.ui \
    ../Game/storydialog.ui

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

