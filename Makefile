CC=gcc 
FLAGS= -fopenmp  -lm
EXECS= bug2 bug3 bug4 bug5 bug6 jacobi-omp GS-omp

all: ${EXECS}


bug2: omp_solved2.c
	${CC} ${FLAGS} $^ -o omp_solved2

bug3: omp_solved3.c
	${CC} ${FLAGS} $^ -o omp_solved3

bug4: omp_solved4.c
	${CC} ${FLAGS} $^ -o omp_solved4

bug5: omp_solved5.c
	${CC} ${FLAGS} $^ -o omp_solved5

bug6: omp_solved6.c
	${CC} ${FLAGS} $^ -o omp_solved6

jacobi-omp: jacobi2D-omp.c
	${CC} ${FLAGS} $^ -o jacobi2D-omp

jacobi-omp: jacobi2D-omp.c
	${CC} -lm -lrt $^ -o jacobi2D


GS-omp: gs2D-omp.c
	${CC} ${FLAGS} $^ -o gs2D-omp

GS-omp: gs2D-omp.c
	${CC} -lm -lrt $^ -o gs2D

clean:
	rm -f ${EXECS}