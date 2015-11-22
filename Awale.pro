TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    Core/awale.cpp \
    Core/game.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Core/awale.h \
    Core/game.h

