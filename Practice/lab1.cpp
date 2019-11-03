#include<iostream>
#include<omp.h>

using namespace std;

int main(){
    int num = omp_get_max_threads();
    cout<<"Num threads: "<<num<<endl;
    int n = 400;
    double a[n][n], b[n][n], c[n][n];
    int i,j,k;
    double wtime = omp_get_wtime();
    srand(time(0));
    #pragma omp shared(a,b,c,n) private(i,j,k)
    {
        #pragma omp for
        for( i = 0; i<n;i++){
            for( j=0; j<n; j++){
                a[i][j] = rand()%100;
            }
        }

        #pragma omp for
        for( i = 0; i<n;i++){
            for( j=0; j<n; j++){
                b[i][j] = rand()%100;
            }
        }

        #pragma omp for schedule(static)
        for( i =0; i<n; i++){
            for( j = 0; j<n; j++){
                c[i][j] = 0.0;
                for(k=0; k<n; k++){
                    c[i][j] += a[i][k] + b[k][j];
                }
            }
        }
    }
    wtime = omp_get_wtime() - wtime;
    cout<<endl<<"Time taken: "<<wtime<<endl;
    return 0;
}