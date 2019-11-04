#ifdef _POMP
#  undef _POMP
#endif
#define _POMP 200110

#include "/home/maybeabhishek/Documents/Projects/PDC_Lab/Practice/lab2.cpp.opari.inc"
#line 1 "/home/maybeabhishek/Documents/Projects/PDC_Lab/Practice/lab2.cpp"

#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int32_t n = 1000;
    long double fac = 1;
    clock_t t;
    t = omp_get_wtime();
    omp_set_num_threads(200);
POMP_Parallel_fork(&omp_rd_1);
#line 13 "/home/maybeabhishek/Documents/Projects/PDC_Lab/Practice/lab2.cpp"
    #pragma omp parallel                       
{ POMP_Parallel_begin(&omp_rd_1);
POMP_For_enter(&omp_rd_1);
#line 13 "/home/maybeabhishek/Documents/Projects/PDC_Lab/Practice/lab2.cpp"
    #pragma omp          for schedule(guided,4) nowait
        for(int32_t i = 1; i<=n; i++){
            fac*=i;
        }
POMP_Barrier_enter(&omp_rd_1);
#pragma omp barrier
POMP_Barrier_exit(&omp_rd_1);
POMP_For_exit(&omp_rd_1);
POMP_Parallel_end(&omp_rd_1); }
POMP_Parallel_join(&omp_rd_1);
#line 17 "/home/maybeabhishek/Documents/Projects/PDC_Lab/Practice/lab2.cpp"
            cout << fac << endl;
    
    t = omp_get_wtime() - t;
    cout<<"Num threads: "<<(int)omp_get_num_procs()<<endl;
    cout << "Time taken to run: "<<(float)t/CLOCKS_PER_SEC<<endl;
}
