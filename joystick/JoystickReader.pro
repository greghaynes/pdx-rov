TEMPLATE = app
QT = gui core
CONFIG += qt release warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
LIBS +=-L/usr/lib64/ -ljoystick++
LIBS+=-L/usr/lib64/kde4/devel -lkdeui
FORMS = ui/mainwindow.ui
HEADERS = src/mainwindowimpl.h
SOURCES = src/mainwindowimpl.cpp src/main.cpp
