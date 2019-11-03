EXECS=mpiworld
MPICC?=mpicc

all: ${EXECS}

mpiworld: mpiworld.c
	${MPICC} -o mpiworld mpiworld.c

clean:
	rm -f ${EXECS}