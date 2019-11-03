//  Section 1 c[i] = a[i] + b[i]
// Setion 2 c[i] = a[i] * b[i]
// Section 3 c[i] = a[i]^2

#include <omp.h>
#include <iostream>

using namespace std;

const int N = 5000;
double a[N],b[N],c[N];

int main(){
    #pragma omp parallel 
    {
        for(int i = 0; i< N; i++){
            a[i] = i*2;
            b[i] = i+2;
        }
    }
    #pragma omp parallel sections 
    {
        #pragma omp section
        { 
            printf ("id = %d, \n", omp_get_thread_num());
            #pragma omp parallel for
            for(int i = 0; i< N; i++){
                c[i] = a[i] + b[i];
            }
        }

        #pragma omp section
        { 
            printf ("id = %d, \n", omp_get_thread_num());
            #pragma omp parallel for
            for(int i = 0; i< N; i++){
                c[i] = a[i] * b[i];
            }
        }
    }
    
}