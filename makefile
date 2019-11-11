all: randfilemain.o randfile.o
	gcc -o program randfilemain.o randfile.o

linkedlistmain.o: randfilemain.c randfileh.h
	gcc -c randfilemain.c

linkedlist.o: randfile.c randfileh.h
	gcc -c randfile.c

run:
	./program

clean:
	rm *.o
	rm *~
