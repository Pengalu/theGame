CC=g++
OBJS=Main.cpp Engine.h Engine.cpp Player.h Player.cpp Platform.h Platform.cpp Input.cpp Draw.cpp Update.cpp Base.h Base.cpp
OBJ_NAME=game.out
LINKER_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
CC_FLAGS=

all : $(OBJS)
	$(CC) $(OBJS) $(CC_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

cleanall : $(OBJS)
	rm $(OBJ_NAME)
	$(CC) $(OBJS) $(CC_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

test : $(OBJS)
	$(CC) $(OBJS) $(CC_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)

cleantest : $(OBJS)
	rm $(OBJ_NAME)
	$(CC) $(OBJS) $(CC_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)
clean : $(OBJS)
	rm $(OBJ_NAME)
allexe : $(OBJS)
	$(CC) $(OBJS) $(CC_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME).exe