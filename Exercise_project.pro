TEMPLATE = subdirs

SUBDIRS += \
    CourseLib \
    Game \
    UnitTest

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib
UnitTests.depends = CourseLib
