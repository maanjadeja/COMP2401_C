OBJ = mystat.o person.o main.o
OUT = main

all: mystat person main
	gcc -o $(OUT) $(OBJ)

mystat: mystat.c mystat.h
	gcc -c mystat.c

person.o: person.h person.c mystat.h
	gcc -c person.c

main: main.c person.h
	gcc -c main.c

clean:
	rm -f $(OBJ) $(OUT)
