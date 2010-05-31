find_package(Qt4 COMPONENTS QtCore QtGui QtNetwork REQUIRED)

INCLUDE(${QT_USE_FILE})

find_package(QJSON  REQUIRED)

set(client_SRCS
	main.cpp
	rovconnection.cpp
	qjoystick.cpp
	joysticksmodel.cpp
	mainwindow.cpp
	motorslider.cpp
	varmonitorbuilder.cpp
	createjoystickdialog.cpp
	connectionmanager.cpp
	createvarmonitordialog.cpp
	varmonitorcreationprogressdialog.cpp
	varmonitor.cpp
	servowidget.cpp
	rovjoystick.cpp
	armjoystick.cpp
	propjoystick.cpp)

set(ui_SRCS
	createjoystickwidget.ui
	createvarmonitorwidget.ui
	createconnectionwidget.ui)

QT4_AUTOMOC(${client_SRCS})
QT4_WRAP_UI(client_SRCS ${ui_SRCS})

add_executable(client ${client_SRCS})

target_link_libraries(client ${QT_LIBRARIES} ${QJSON_LIBRARIES})

