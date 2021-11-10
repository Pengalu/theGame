CC=g++
inhpp=*.hpp
incpp=*.cpp
in=$(inhpp) $(incpp)
out=game.out
if=if [ -f $(out) ];
then=then rm $(out); fi
rmout=$(if) $(then)
linkerflags=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
CCflags=-Wall

all : $(in)
	$(rmout)
	$(CC) $(in) $(CCflags) $(linkerflags) -o $(out)

alltest : $(in)
	$(rmout)
	$(CC) $(in) $(CCflags) $(linkerflags) -o $(out)
	./$(out)

debug : $(in)
	$(rmout)
	$(CC) -g $(in) $(CCflags) $(linkerflags) -o $(out)
