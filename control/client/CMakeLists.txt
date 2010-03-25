find_package(Qt4 COMPONENTS QtCore QtGui QtNetwork REQUIRED)

INCLUDE(${QT_USE_FILE})

set(client_SRCS
	main.cpp
	rovconnection.cpp
	qjoystick.cpp
	joysticksmodel.cpp
	mainwindow.cpp
	createjoystickdialog.cpp
	rovjoystick.cpp)

set(ui_SRCS
	createjoystickwidget.ui)

QT4_AUTOMOC(${client_SRCS})
QT4_WRAP_UI(client_SRCS ${ui_SRCS})

add_executable(client ${client_SRCS})

target_link_libraries(client ${QT_LIBRARIES})

