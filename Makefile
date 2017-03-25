#
# To use this makefile use 'make build' then use 'make run' 
# 'make list' will ls all directories including the build directory
# 'make clean' will clear out the object files in the sub directories, as well as clean up the build directory
#

# Unset/Set CFLAGS for sanity checks and debugging 
#CFLAGS = -Wpedantic -Wall -g -DDEBUG
CFLAGS = -Wall -Wpedantic -std=c99
LIBS = -lm
CC = gcc
BUILDDIR = ~/Documents/SeniorDesign/QuadSovler/Build

build: IO.o qSolve.o mySqrt.o output.o
	cp ${BUILDDIR}/IO/IO.* ${BUILDDIR}
	cp ${BUILDDIR}/qSolve/qSolve.* ${BUILDDIR}
	cp ${BUILDDIR}/mySqrt/mySqrt.* ${BUILDDIR}
	cp ${BUILDDIR}/output/output.* ${BUILDDIR}
	${CC} ${CFLAGS} -o QSolver main.c IO.o qSolve.o mySqrt.o output.o ${LIBS}

run: 
	./QSolver

list:
	cd ${BUILDDIR}/IO; ls
	cd ${BUILDDIR}/qSolve; ls
	cd ${BUILDDIR}/mySqrt; ls
	cd ${BUILDDIR}/output; ls 
	ls

IO.o:
	+$(MAKE) -C	IO

qSolve.o:
	+$(MAKE) -C qSolve

mySqrt.o:
	+$(MAKE) -C	mySqrt

output.o:
	+$(MAKE) -C output

clean: 
	cd ${BUILDDIR}/IO; rm *.o
	cd ${BUILDDIR}/qSolve; rm *.o
	cd ${BUILDDIR}/mySqrt; rm *.o
	cd ${BUILDDIR}/output; rm *.o
	rm IO.* output.* qSolve.* mySqrt.* QSolver 
