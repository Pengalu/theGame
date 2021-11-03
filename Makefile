CC=g++
in=Engine.cpp Engine.hpp Main.cpp Window.cpp Window.hpp WorkingDirectory.cpp WorkingDirectory.hpp Bitmask.cpp Bitmask.hpp Input.cpp Input.hpp
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