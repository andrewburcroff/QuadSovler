# Unset/Set CFLAGS for sanity checks and debugging 
#CFLAGS = -Wpedantic -Wall -g -DDEBUG
CFLAGS = -Wall -Wpedantic -std=c99
LIBS = -lm
CC = gcc
BUILDDIR = ~/Documents/SeniorDesign/QuadSovler

IO.o:	IO.c IO.h	

IOTest.o:	IOTest.c IOTest.h

testIO:	IOTest.o
	${CC} ${CFLAGS} -o IOTester TestMain.c IOTest.o ${LIBS}
	./IOTester > TestOutput.txt

clean:
	rm *.o IOTester TestOutput.txt
