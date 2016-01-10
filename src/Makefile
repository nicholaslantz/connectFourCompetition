

CFLAGS=-std=c++11
LIBS=/usr/local/lib/libStanfordCPPLib.a
OBJECTS = main.o engine/board.o engine/connectfour.o engine/interface.o \
	userinterface/userinterface.o engine/gamemanager.o


CC=g++ 

.SUFFIXES: .cpp .o

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJECTS)
	$(CC) $^ -o ConnectFour $(LIBS)

clean:
	$(RM) `find . | grep -F .o`
	$(RM) ConnectFour
