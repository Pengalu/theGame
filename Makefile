CC=g++

# in files
inhpp=*.hpp
incpp=*.cpp
in=$(inhpp) $(incpp)

# out file
out=game.out

# if for removal
if=if [ -f $(out) ];
then=then rm $(out); fi
rmout=$(if) $(then)

# flags
linkerflags=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
CCflags=-Wall

# counting lines
counter=cloc
clocflags=--exclude-lang=make --by-file


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

count : *
	$(counter) * $(clocflags)

countbl : *
	$(counter) * $(clocflags)-by-lang