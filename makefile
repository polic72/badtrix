PROG = badtrix
OBJS = obj/$(PROG).o obj/extras.o obj/matrix.o obj/vector.o

DOC = doc/html

CC = gcc
CFLAGS = 
LIBS = 
DEBUGFLAGS = 


#all : $(PROG) $(DOC)
all : bin/$(PROG)


debug : CFLAGS += -DDEBUG -g -O
debug : all


bin/$(PROG) : $(OBJS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(OBJS) -o bin/$(PROG) $(LIBS) -Wall -lm
	ln -s bin/$(PROG) $(PROG)

$(DOC) : Doxyfile *.c
	doxygen

obj/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o "$@" $(DEBUGFLAGS) $(LIBS) -Wall -lm


clean:
	rm -f $(OBJS) $(PROG)
	rm -rf $(DOC)
	rm -rf bin
	rm -rf obj
