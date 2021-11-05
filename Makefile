CC=g++
in=*.hpp *.cpp
out=game.out
linkerflags=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
CCflags=-Wall

all : $(in)
	$(CC) $(in) $(CCflags) $(linkerflags) -o $(out)

allclean : $(in)
	rm $(out)
	$(CC) $(in) $(CCflags) $(linkerflags) -o $(out)

alltest : $(in)
	rm $(out)
	$(CC) $(in) $(CCflags) $(linkerflags) -o $(out)
	./$(out)
