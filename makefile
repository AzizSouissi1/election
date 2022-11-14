prog:election.c main.o
	gcc election.o main.o -o prog -g
main.o:main.c
	gcc -c main.c -g
fonction.o:election.c
	gcc -c election.c -g
