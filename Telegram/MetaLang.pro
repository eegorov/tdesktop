QT += core

CONFIG(debug, debug|release) {
    DEFINES += _DEBUG
    OBJECTS_DIR = ./../DebugIntermediateLang
    MOC_DIR = ./GeneratedFiles/Debug
    DESTDIR = ./../DebugLang
}
CONFIG(release, debug|release) {
    OBJECTS_DIR = ./../ReleaseIntermediateLang
    MOC_DIR = ./GeneratedFiles/Release
    DESTDIR = ./../ReleaseLang
}

CONFIG += plugin static c++11

macx {
    QMAKE_INFO_PLIST = ./SourceFiles/_other/Lang.plist
    QMAKE_LFLAGS += -framework Cocoa
}

SOURCES += \
    ./SourceFiles/_other/mlmain.cpp \
    ./SourceFiles/_other/genlang.cpp \

HEADERS += \
    ./SourceFiles/_other/mlmain.h \
    ./SourceFiles/_other/genlang.h \

INCLUDEPATH += /opt/telegram-qtstatic/include/QtGui/5.5.1/QtGui\
               /opt/telegram-qtstatic/include/QtCore/5.5.1/QtCore\
               /opt/telegram-qtstatic/include\

