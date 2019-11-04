//Section 1 c[i] = a[i] + b[i]
// Setion 2 c[i] = a[i] * b[i]
// Section 3 c[i] = a[i]^2

#include<iostream>
#include<omp.h>
#include<math.h>

using namespace std;

int main(){

    int num = omp_get_max_threads();
    cout<<"Num threads: "<<num<<endl;
    int n = 400;
    double a[n], b[n], c[n], d[n], e[n];
    int i,j,k;

    for( i = 0; i<n;i++){
        a[i] = rand()%100;
    }
        
    for( i = 0; i<n;i++){
        b[i] = rand()%100;
    }
        

    double wtime = omp_get_wtime();
    srand(time(0));


    #pragma omp shared(a,b,c,n) private(i,j,k)
    {
        
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                for(i=0; i<n; i++){
                    c[i] = a[i]+b[i];
                }
            }

            #pragma omp section
            {
                for(j=0; j<n; j++){
                    d[j] = a[j]*b[j];
                }
            }

            #pragma omp section
            {
                for(k=0; k<n; k++){
                    e[k] = pow(a[k],b[k]);
                }
            }
        }

    }
    wtime = omp_get_wtime() - wtime;
    cout<<"Time taken: "<<wtime<<endl;
    return 0;
}