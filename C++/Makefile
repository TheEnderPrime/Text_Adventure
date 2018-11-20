CFLAGS = -O
CC = g++

Play: Game.o Player.o
	$(CC) $(CFLAGS) -o Play Game.o Player.o

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

Player.o: Player.cpp
	$(CC) $(CFLAGS) -c Player.cpp

clean:
	rm -f core *.o