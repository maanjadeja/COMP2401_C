OBJ = display.o rrtMaker.o rrtTester.o
OUT = rrtTester

all:	display rrtMaker rrtTester
	gcc -o $(OUT) $(OBJ) -lX11 -lm -g

display: display.c display.h obstacles.h
	gcc -c display.c -g

rrtMaker:	rrtMaker.c display.h obstacles.h
	gcc -c rrtMaker.c -g

rrtTester:	rrtTester.c display.h	obstacles.h
	gcc -c rrtTester.c -g

clean:
	rm -f $(OBJ) $(OUT)
