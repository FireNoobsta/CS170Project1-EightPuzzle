OBJS	= searches.o main.o

CC	= g++
CFLAGS	= -g -Wall -std=c++11

puzzle:		$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o puzzle

searches.o:	searches.cpp eightpuzzle.h searches.h node.h
		$(CC) $(CFLAGS) -c searches.cpp -o searches.o

main.o:		main.cpp eightpuzzle.h searches.h node.h
		$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o puzzle
