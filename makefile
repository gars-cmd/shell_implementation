FLAG = -Wall -g

all: main.o server server.o shell 

main.o: main.c 
	gcc $(FLAG) -c main.c

command.o: command.c
	gcc $(FLAG) -c command.c

server.o: server.c
	gcc $(FLAG) -c server.c

server: server.o
	gcc -o server server.o

shell: main.o command.o
	gcc $(FLAG) -o shell main.o command.o

.PHONY: clean all

clean:
	rm -f *.o shell 

run:
	./shell