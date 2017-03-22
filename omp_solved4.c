/******************************************************************************
* FILE: omp_solved4.c
* DESCRIPTION:
*   Fixed size array may cause stack size exceed error. Allocate the array inside
* the parrallel  region dynamically can solve this problem.
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1048


int main (int argc, char *argv[]) 
{
int nthreads, tid, i, j;
double * a; 
/* double a[N][N]; */
/* omp_set_num_threads(1); */
setenv("GOMP_STACKSIZE","500 M",1);
/* Fork a team of threads with explicit variable scoping */
#pragma omp parallel shared(nthreads) private(i,j,tid,a) 
  {
  
  /* Obtain/print thread info */
  tid = omp_get_thread_num();
  if (tid == 0) 
    {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }
  printf("Thread %d starting...\n", tid);

  /* Each thread works on its own private copy of the array */
  	
  a = (double *) malloc(sizeof(double) * N*N);

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      a[i*N+j] = tid + i + j;


  /* For confirmation */
  printf("Thread %d done. Last element= %f\n",tid,a[(N-1)*N+N-1]);

  }  /* All threads join master thread and disband */

}

