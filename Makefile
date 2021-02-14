OBJS	= searches.o main.o

CC	= g++
CFLAGS	= -g -Wall

puzzle:		$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o puzzle

searches.o:	searches.cpp
		$(CC) $(CFLAGS) -c searches.cpp -o searches.o

main.o:		main.cpp
		$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o puzzle
