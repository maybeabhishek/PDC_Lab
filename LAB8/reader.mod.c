#ifdef _POMP
#  undef _POMP
#endif
#define _POMP 200110

#include "reader.c.opari.inc"
#line 1 "reader.c"
// #include<iostream>

#include<stdio.h>
#include<omp.h>
#include<string.h>

// using namespace std;

int main()
{
    char buffer[100];
    strcpy(buffer,"VIT");
    int i;
    omp_set_num_threads(8);
    omp_lock_t harit;
    POMP_Init_lock(&harit);
POMP_Parallel_fork(&omp_rd_1);
#line 17 "reader.c"
    #pragma omp parallel POMP_DLIST_00001
{ POMP_Parallel_begin(&omp_rd_1);
#line 18 "reader.c"
    {
        int tid=omp_get_thread_num();
        if(tid==0)
        {
            POMP_Set_lock(&harit);
            printf("Thread:%d is now wrting the data to the buffer \n",omp_get_thread_num());
            strcat(buffer," Chennai");
            POMP_Unset_lock(&harit);
        }
        if(tid==3)
        {
            POMP_Set_lock(&harit);
            printf("Thread:%d is now wrting the data to the buffer \n",omp_get_thread_num());
            strcat(buffer," Campus");
            POMP_Unset_lock(&harit);
        }
        if(tid!=0 && tid!=3)
        {
            POMP_Set_lock(&harit);
            printf("the buffer contains: %s = %d\n",buffer,omp_get_thread_num());
            POMP_Unset_lock(&harit);
        }
    }
POMP_Barrier_enter(&omp_rd_1);
#pragma omp barrier
POMP_Barrier_exit(&omp_rd_1);
POMP_Parallel_end(&omp_rd_1); }
POMP_Parallel_join(&omp_rd_1);
#line 41 "reader.c"
    return 0;
}
