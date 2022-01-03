CC = gcc
FLAGS = -Wall -g

all:graph s d    

graph: main.o  libds.a 
		$(CC) $(FLAGS) -o graph  main.o libds.a -lm


  

s: libds.a

d : libdd.so



libds.a: main.o miheap.o miheap.h
	ar -rcs libds.a miheap.o miheap.h

libdd.so:main.o miheap.h  miheap.o
	$(CC) -shared -o libdd.so miheap.h  miheap.o



main.o:main.c miheap.h
	$(CC) $(FLAGS) -c main.c -lm



myheap.o: miheap.c
	$(CC) $(FLAGS) -c miheap.c


.PHONY:	clean all
clean:
	rm -f *.o  graph s d libds.a libdd.so