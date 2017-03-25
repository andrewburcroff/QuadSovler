# Unset/Set CFLAGS for sanity checks and debugging 
#CFLAGS = -Wpedantic -Wall -g -DDEBUG
CFLAGS = -Wall -Wpedantic -std=c99
LIBS = -lm
CC = gcc

mySqrt.o: mySqrt.c mySqrt.h

test: mySqrt.o
	${CC} ${CFLAGS} -o mySqrtTester mySqrtTester.c mySqrt.o ${LIBS}
	./mySqrtTester > TestOuput.txt

debug: mySqrt.o
	${CC} ${CFLAGS} -o mySqrtTester mySqrtTester.c mySqrt.o ${LIBS}
	gdb mySqrtTester

clean:
	rm *.o
