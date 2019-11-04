
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include<time.h>
#define N 100000

int main(){

    unsigned long int a[N];
    srand(time(0));
    unsigned long int i;
    for(i = 0;i < N;i++){
        a[i] = rand();
        printf("%d\n",a[i]);
    }
   
    unsigned long int sum = 0;
    printf("Without parallel\n");
    double stime = omp_get_wtime();
    for(i =0;i<N;i++)
        if(a[i] > sum)
            sum = a[i];
    double ttime = omp_get_wtime() - stime;
    printf("Sum: %d\nTotal time: %f\n\n",sum,ttime);
    
    sum = 0;
    printf("With parallel\n");
    stime = omp_get_wtime();
    #pragma omp parallel for num_threads(8) reduction(max:sum)
    for(i =0;i<N;i++)
        if(a[i] > sum)
            sum = a[i];
    
    ttime = omp_get_wtime() - stime;
    printf("Sum: %d\nTotal time: %f\n\n",sum,ttime);
    return 0;
}

