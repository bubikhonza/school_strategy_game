TEMPLATE = app
TARGET = TheGame

QT += core gui widgets multimedia

CONFIG += c++14

SOURCES += \
    buildings/fortress.cpp \
    tiles/desert.cpp \
    core/gameeventhandler.cpp \
    core/gameover.cpp \
    core/gamescene.cpp \
    core/howtoplay.cpp \
    main.cpp \
    core/mapitem.cpp \
    core/mapwindow.cc \
    core/menuwindow.cpp \
    buildings/mine.cpp \
    tiles/mountains.cpp \
    core/objectmanager.cpp \
    core/player.cpp \
    buildings/sawmill.cpp \
    core/storydialog.cpp \
    tiles/swamp.cpp \
    workers/leader.cpp \
    workers/aristocrat.cpp \
    workers/engineerworker.cpp \

HEADERS += \
    buildings/fortress.h \
    tiles/desert.h \
    core/gameeventhandler.h \
    core/gameover.h \
    core/gamescene.h \
    core/howtoplay.h \
    core/mapitem.h \
    core/mapwindow.hh \
    core/menuwindow.h \
    buildings/mine.h \
    tiles/mountains.h \
    core/myresourcemaps.h \
    core/objectmanager.h \
    core/player.h \
    buildings/sawmill.h \
    core/storydialog.h \
    tiles/swamp.h \
    workers/leader.h \
    workers/aristocrat.h \
    workers/engineerworker.h \

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

message($OUT_PWD)

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    gameover.ui \
    howtoplay.ui \
    mapwindow.ui \
    menuwindow.ui \
    storydialog.ui

RESOURCES += \
    Resource.qrc

DISTFILES += \
    images/stone.png

