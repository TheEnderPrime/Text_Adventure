CFLAGS = -O
CC = g++

Play: Game.o Player.o ASCII.o
	$(CC) $(CFLAGS) -o Play Game.o Player.o ASCII.o

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

Player.o: Player.cpp
	$(CC) $(CFLAGS) -c Player.cpp

ASCII.o: ASCII.cpp
	$(CC) $(CFLAGS) -c ASCII.cpp

clean:
	rm -f core *.o