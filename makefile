PROG = badtrix
OBJS = $(PROG).o extras.o matrix.o vector.o

DOC = html

CC = gcc
CFLAGS = 
LIBS = 


#all : $(PROG) $(DOC)
all : $(PROG)


$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG) $(LIBS) -Wall -lm

$(DOC) : Doxyfile *.c
	doxygen

%.o : %.c
	$(CC) $(CFLAGS) -c $< $(LIBS)


clean:
	rm -f $(OBJS) $(PROG)
	rm -rf $(DOC)
