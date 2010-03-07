find_package(Qt4 COMPONENTS QtCore QtGui QtNetwork REQUIRED)

INCLUDE(${QT_USE_FILE})

set(client_SRCS
	main.cpp
	rovconnection.cpp
	qjoystick.cpp)

QT4_AUTOMOC(${client_SRCS})

add_executable(client ${client_SRCS})

target_link_libraries(client ${QT_LIBRARIES})

