#include<iostream>
#include<stdio.h>
#include<omp.h>
#include<string.h>

using namespace std;

int main()
{
    char buffer[100];
    strcpy(buffer,"VIT");
    int i;
    omp_set_num_threads(8);
    omp_lock_t harit;
    omp_init_lock(&harit);
    #pragma omp parallel
    {
        int tid=omp_get_thread_num();
        if(tid==0)
        {
            omp_set_lock(&harit);
            printf("Thread:%d is now wrting the data to the buffer \n",omp_get_thread_num());
            strcat(buffer," Chennai");
            omp_unset_lock(&harit);
        }
        if(tid==3)
        {
            omp_set_lock(&harit);
            printf("Thread:%d is now wrting the data to the buffer \n",omp_get_thread_num());
            strcat(buffer," Campus");
            omp_unset_lock(&harit);
        }
        if(tid!=0 && tid!=3)
        {
            omp_set_lock(&harit);
            printf("the buffer contains: %s = %d\n",buffer,omp_get_thread_num());
            omp_unset_lock(&harit);
        }
    }
    return 0;
}