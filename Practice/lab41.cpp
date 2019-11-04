
#include <omp.h>
#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int32_t n = 1000;
    long double fac = 1;
    clock_t t;
    t = omp_get_wtime();
    omp_set_num_threads(200);
    #pragma omp parallel for schedule(guided,4)
        for(int32_t i = 1; i<=n; i++){
            fac*=i;
        }
            cout << fac << endl;
    
    t = omp_get_wtime() - t;
    cout<<"Num threads: "<<(int)omp_get_num_procs()<<endl;
    cout << "Time taken to run: "<<(float)t/CLOCKS_PER_SEC<<endl;
}