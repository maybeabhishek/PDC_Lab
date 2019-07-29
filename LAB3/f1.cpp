
#include <omp.h>
#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int32_t n = 1000;
    long double fac = 1;
    clock_t t;
    t = clock();
    #pragma omp parallel for schedule(guided,4)
        for(int32_t i = 1; i<=n; i++){
            fac*=i;
        }
            cout << fac << endl;
    
    t = clock() - t;
    cout << "Time taken to run: "<<(float)t/CLOCKS_PER_SEC<<endl;
}