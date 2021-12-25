CC = gcc
FLAGS = -Wall -g

all:stringProg s d    

stringProg: main.o  libds.a 
		$(CC) $(FLAGS) -o stringProg  main.o libds.a -lm


  

s: libds.a

d : libdd.so



libds.a: main.o miheap.o miheap.h
	ar -rcs libds.a miheap.o miheap.h

libdd.so:main.o miheap.h  miheap.o
	$(CC) -shared -o libdd.so miheap.h  miheap.o



main.o:main.c miheap.h
	$(CC) $(FLAGS) -c main.c -lm



my_mat.o: miheap.c
	$(CC) $(FLAGS) -c miheap.c


.PHONY:	clean all
clean:
	rm -f *.o  stringProg s d libds.a libdd.so