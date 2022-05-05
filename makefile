
CC = gcc
flags = -Wall -Wundef -Wpedantic -Werror

finished: funciones_t2.o main_tarea2.o
	$(CC) $(flags) main_tarea2.o funciones_t2.o -o finished.exe

funciones_t2.o: funciones_t2.c
	$(CC) $(flags) -o funciones_t2.o -c funciones_t2.c

main_tarea2.o: main_tarea2.c
	$(CC) $(flags) -o main_tarea2.o -c main_tarea2.c

clean:
	rm finished.exe *.o