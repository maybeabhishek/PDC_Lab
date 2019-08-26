#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    int a[100],i;
    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i<100; i++)
            a[i]=i*i;

        #pragma omp master
        for(int i =0; i<100; i++)
            printf("a[%d] = %d\n",i,a[i]);
        
        //wait
        #pragma omp barrier

        #pragma omp for
        for(int i = 0; i<100; i++)
            a[i]+=i;
    }
}