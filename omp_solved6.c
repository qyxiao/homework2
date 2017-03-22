/******************************************************************************
* FILE: omp_solved6.c
* DESCRIPTION:
*   'sum' is shared before entering 'drop()' but then tries to become private.
*   Declare 'sum' to be private before entering the function drop() to insure consistency.
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define VECLEN 100

float a[VECLEN], b[VECLEN];
float sum;

float dotprod ()
{
int i,tid;


tid = omp_get_thread_num();
#pragma omp for 
  for (i=0; i < VECLEN; i++)
    {
    sum = sum + (a[i]*b[i]);
    printf("  tid= %d i=%d\n",tid,i);
    }
}


int main (int argc, char *argv[]) {
int i;


for (i=0; i < VECLEN; i++)
  a[i] = b[i] = 1.0 * i;
sum = 0.0;

#pragma omp parallel reduction(+:sum)
  dotprod();

printf("Sum = %f\n",sum);

}