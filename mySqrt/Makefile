# Unset/Set CFLAGS for sanity checks and debugging 
#CFLAGS = -Wpedantic -Wall -g -DDEBUG
CFLAGS = -Wall -Wpedantic -std=c99
LIBS = -lm
CC = gcc

mySqrt.o: mySqrt.c mySqrt.h

mySqrtMock.o: mySqrtMock.c mySqrtMock.h

testmySqrt: mySqrtMock.o
	${CC} ${CFLAGS} -o mySqrtTester mySqrtTester.c mySqrtMock.o ${LIBS}
	./mySqrtTester > TestOutput.txt

debug: mySqrt.o
	${CC} ${CFLAGS} -o mySqrtTester mySqrtTester.c mySqrt.o ${LIBS}
	gdb mySqrtTester

clean:
	rm *.o mySqrtTester TestOutput.txt
