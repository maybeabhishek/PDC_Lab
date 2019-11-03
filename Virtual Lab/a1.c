#include <stdio.h>
#include <math.h>
#include <omp.h>

void main (){

    static int array[10][10];
    int i, j, m, n, sum = 0, sum1 = 0, a = 0, normal;

    for (i = 0; i < 10; ++i) 
    {
        for (j = 0; j < 10; ++j)
        {
            array[i][j] = i*j*7;
        }
    }

    #pragma omp parallel for
    for (i = 0; i < 10; ++i) 
    {
        sum = sum + array[i][i];
    }
    printf("Trace of the matrix is = %d\n", sum);

}