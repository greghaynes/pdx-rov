find_package(Qt4 COMPONENTS QtCore QtGui QtNetwork QtWebKit REQUIRED)

INCLUDE(${QT_USE_FILE})

set(common_SRCS
	rovconnection.cpp
	qjoystick.cpp
	motorslider.cpp
	motorpanel.cpp
	servodial.cpp
	armpanel.cpp
	sensorpanel.cpp
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

set(pilot_SRCS
	pilotwindow.cpp
	pilot.cpp)

set(control_SRCS
	controlwindow.cpp
	control.cpp)

set(ui_SRCS
	createjoystickwidget.ui
	createvarmonitorwidget.ui
	createconnectionwidget.ui
	sensorspanel.ui)

QT4_AUTOMOC(${common_SRCS})
QT4_AUTOMOC(${pilot_SRCS})
QT4_AUTOMOC(${control_SRCS})
QT4_WRAP_UI(client_SRCS ${ui_SRCS})

add_executable(pilot ${common_SRCS} ${pilot_SRCS})
target_link_libraries(pilot ${QT_LIBRARIES})

add_executable(control ${common_SRCS} ${control_SRCS})
target_link_libraries(control ${QT_LIBRARIES})

