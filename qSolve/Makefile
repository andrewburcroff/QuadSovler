# Unset/Set CFLAGS for sanity checks and debugging 
#CFLAGS = -Wpedantic -Wall -DDEBUG -std=c99
CFLAGS = -Wall -Wpedantic -std=c99
LIBS = -lm
CC = gcc

qSolve.o: qSolve.c qSolve.h

test: qSolve.o
	${CC} ${CFLAGS} -o qSolveTester qSolveTester.c qSolve.o ${LIBS}
	./qSolveTester > TestOuput.txt

debug: qSolve.o
	${CC} ${CFLAGS} -o qSolveTester qSolveTester.c qSolve.o ${LIBS}
	gdb qSolveTester

clean:
	rm *.o qSolveTester 
