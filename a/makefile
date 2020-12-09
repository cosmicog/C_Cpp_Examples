CC=gcc


all: a.o

sample.o: RoboteqDevice.o
	$(CC) RoboteqDevice.o a.c -o a.o

clean:
	rm *.o