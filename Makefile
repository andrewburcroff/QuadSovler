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
BUILDDIR = ~/Documents/SeniorDesign/QuadSolverV2

build: IO.o qSolve.o mySqrt.o output.o
	cp ${BUILDDIR}/IO/IO.* ${BUILDDIR}
	cp ${BUILDDIR}/qSolve/qSolve.* ${BUILDDIR}
	cp ${BUILDDIR}/mySqrt/mySqrt.* ${BUILDDIR}
	cp ${BUILDDIR}/output/output.* ${BUILDDIR}
	${CC} ${CFLAGS} -o QSolver main.c IO.o qSolve.o mySqrt.o output.o ${LIBS}

run: 
	./QSolver

unittest:
	+$(MAKE) -C	IO testIO
	+$(MAKE) -C qSolve testqSolve
	+$(MAKE) -C	mySqrt	testmySqrt

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
	+$(MAKE) -C	IO clean;
	+$(MAKE) -C qSolve clean;
	+$(MAKE) -C	mySqrt clean;
	+$(MAKE) -C output clean;
	rm IO.* output.* qSolve.* mySqrt.* QSolver
	rm IO.* output.* qSolve.* mySqrt.* QSolver 
