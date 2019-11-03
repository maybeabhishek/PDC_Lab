#include<stdio.h>
#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    int x;
    omp_lock_t harit;
    omp_init_lock (&harit);
    x=0;
    #pragma omp parallel shared(x)
    {
        omp_set_lock (&harit);
        x=x+1;
        printf("value of x=%d and thread which updated is %d \n",x,omp_get_thread_num());
        omp_unset_lock (&harit);
    }
    printf("Final value of x=%d\n",x);
    omp_destroy_lock (&harit);
}