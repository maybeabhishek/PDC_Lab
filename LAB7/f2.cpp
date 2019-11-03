#include <iostream>
#include <omp.h>
#include<math.h>
#define N 100000

using namespace std;

int main(){
    int64_t a[N];
    srand(time(0));
    for(auto i = 0; i<N;i++){
        a[i]=rand(); 
    }
    int64_t sum = 0;
    double wtime = omp_get_wtime();
    for(auto i = 0; i<N;i++){
        if(a[i]>sum)
            sum = a[i];
    }
        
        // sum += log(sin((a[i])%10000));
    wtime = omp_get_wtime() - wtime;
    cout << "Time taken to run: "<<wtime<<endl;
    cout<<sum<<endl<<endl;

    sum =0;
    double stime = omp_get_wtime();
    #pragma omp parallel for reduction(max: sum) 
        for(auto i = 0; i<N;i++){
        if(a[i]>sum)
            sum = a[i];
    }
        // sum += log(sin((a[i])%10000));
    stime = omp_get_wtime() - stime;
    cout << "Time taken to run with parallel: "<<stime<<endl;
    cout<<sum<<endl<<endl;
}