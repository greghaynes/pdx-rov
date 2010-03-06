project(server)

set(server_SRCS
	request.c
	main.c)

add_executable(server ${server_SRCS})
target_link_libraries(server event)

