project: bank.c main.c see.c view.c
	cc -c bank.c
	cc -c main.c
	cc -c see.c
	cc -c view.c
	cc bank.o main.o see.o view.o -o project
	
