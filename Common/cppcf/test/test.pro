include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

LIBS += -L$$PWD/../Debug -lcfcpp
INCLUDEPATH += $$PWD/../

HEADERS += \
        tst_test_stream.h

SOURCES += \
        main.cpp
