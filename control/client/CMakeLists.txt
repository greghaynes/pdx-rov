find_package(Qt4 REQUIRED)

INCLUDE(${QT_USE_FILE})

set(client_SRCS
	qjoystick.cpp)

add_executable(client ${client_SRCS})

target_link_libraries(client ${QT_LIBRARIES})

