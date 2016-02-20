TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    Core/awale.cpp \
    Core/game.cpp \
    Core/graphbuilder.cpp \
    Core/holeevaluator.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Core/awale.h \
    Core/game.h \
    Core/graphbuilder.h \
    Core/holeevaluator.h

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml
