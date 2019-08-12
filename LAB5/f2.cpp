#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    int x = 0,y=0;
    #pragma omp parallel num_threads(40)
    {
        #pragma omp single
        x++;
        #pragma omp critical 
        y++;
    }
    cout <<"Single: "<< x<<endl;
    cout <<"Parallel: "<< y<<endl;
}