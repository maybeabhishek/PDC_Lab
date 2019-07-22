#include <stdio.h>
#include <iostream>
#include <omp.h>
using namespace std;
int main(){
    int tid;
    #pragma omp parallel
    {
        tid = omp_get_num_threads();
        int numthread = omp_get_thread_num();
        printf("Welcome to openmp = %d is running on %d thread\n",tid,numthread);
        int cpu = omp_get_num_procs();
        cout << "There are "<<cpu<<" CPUs"<<endl;

    }
}