CFLAGS= -c -g  -I/usr/local/include -Wno-deprecated
LDFLAGS= -L/usr/local/lib -lSDL2 -lSDL2main -lSDL2_image
CC=g++
all: main

debug: CFLAGS+= -DDEBUG
debug: all


main: Entity.o Graphics.o Level.o Tile.o Boundary.o GameEngine.o AnimatedSprite.o Sprite.o main.o
	$(CC) $(LDFLAGS) Entity.o Tile.o Level.o Graphics.o Boundary.o Sprite.o AnimatedSprite.o GameEngine.o main.o -o main

main.o:
	$(CC) $(CFLAGS) main.cpp

Graphics.o:
	$(CC) $(CFLAGS) Graphics.cpp Graphics.h

Entity.o:
	$(CC) $(CFLAGS) Entity.cpp Entity.h

GameEngine.o:
	$(CC) $(CFLAGS) GameEngine.cpp GameEngine.h

Sprite.o:
	$(CC) $(CFLAGS) Sprite.cpp Sprite.h
AnimatedSprite.o: 
	$(CC) $(CFLAGS) AnimatedSprite.cpp AnimatedSprite.h
Boundary.o:
	$(CC) $(CFLAGS) Boundary.cpp Boundary.h
Tile.o:
	$(CC) $(CFLAGS) Tile.cpp Tile.h
Level.o: 
	$(CC) $(CFLAGS) Level.cpp Level.h
clean: 
	rm -rf *.h.gch *.o main
