INCLUDEPATH += "C:/SFML-2.5.1/include"
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}
SOURCES += \
        MusicEffect.cpp \
        boom.cpp \
        bullet.cpp \
        check_collision.cpp \
        items.cpp \
        main.cpp \
        player.cpp

HEADERS += \
    boom.h \
    bullet.h \
    items.h \
    player.h


