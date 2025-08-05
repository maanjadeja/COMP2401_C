OBJ = linkExampleMain.o linkExampleUtil.o

all:  	main util
	gcc -o linkExample $(OBJ)

main: 	linkExampleMain.c linkExampleTypes.h
	gcc -c linkExampleMain.c

util: 	linkExampleUtil.c linkExampleTypes.h
	gcc -c linkExampleUtil.c

clean:
	rm -f $(OBJ) linkExample
