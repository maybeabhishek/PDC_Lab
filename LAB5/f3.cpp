#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    int x[10]= {0,0,0,0,0,0,0,0,0,0};
    int y[10] = {0,0,0,0,0,0,0,0,0,0};
    #pragma omp parallel num_threads(10)
    {
        int mytid = omp_get_thread_num();
        x[mytid] = x[mytid]+5;
        
        #pragma omp barrier
        y[mytid] = x[mytid]+x[mytid]+1;
        cout<<x[mytid]<<"and"<<y[mytid]<<endl;
    }
}