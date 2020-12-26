# paths
MODULES = ../modules
INCLUDE = ../include

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CXXFLAGS = -Wall -g -I$(INCLUDE)

# Αρχεία .o
INCL = $(INCLUDE)/Living_Being.h
OBJS = Role_Playing_Game.o $(MODULES)\Living_Being.o

# Το εκτελέσιμο πρόγραμμα
EXEC = Role_Playing_Game
# Παράμετροι για δοκιμαστική εκτέλεση
ARGS =

$(EXEC): $(OBJS) $(INCL)
	g++ $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)


run: $(EXEC)
	./$(EXEC) $(ARGS)

gdb: $(OBJS)
	g++ $(OBJS) -g3 -o $(EXEC)
	gdb $(EXEC)