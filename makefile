CC=gcc
FLAGS= -Wall -g

all: main libmybank.a
main: main.o libmybank.a
	$(CC) $(FLAGS) -o main main.o libmybank.a
libmybank.a: myBank.o
	ar -rcs libmybank.a myBank.o
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.a *.o main
