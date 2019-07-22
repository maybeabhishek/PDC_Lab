#include <cmath>
#include<stdio.h>
#include <iostream>
#include <time.h>
using namespace std;
int main(){
    clock_t t;
    const int32_t size = 250000;
    double  sinTable[size];
    t = clock();
    #pragma omp parallel for
    for (int n = 0; n < size; n++)
    {
        sinTable[n]= std::sin(2*M_PI*n/size);
    }
    t = clock() - t;
    cout << "Time taken to run: "<<(float)t/CLOCKS_PER_SEC<<endl;
}