all: main.o network.o
	gcc main.o network.o -lv4l2 -o jpeg_cannon

main.o:
	gcc -c main.c -o main.o

network.o:
	gcc -c network.c -o network.o

clean:
	rm jpeg_cannon *.o

