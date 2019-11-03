// C++ implementation of simple approach to 
// find maximum value after m range increments. 
#include<bits/stdc++.h> 
#include<iostream>
#include <openmp.h>
#include <mpi.h>

using namespace std; 

// Function to find maximum value after 'm' operations 
int findMax(int n, int m, int a[], int b[], int k[]) 
{ 
	int arr[n+1]; 
	memset(arr, 0, sizeof(arr)); 
     // Time my_bcast
    // Synchronize before starting timing
    MPI_Barrier(MPI_COMM_WORLD);
    total_my_bcast_time -= MPI_Wtime();
    my_bcast(data, num_elements, MPI_INT, 0, MPI_COMM_WORLD);
    // Synchronize again before obtaining final time
    MPI_Barrier(MPI_COMM_WORLD);
    total_my_bcast_time += MPI_Wtime();

    // Time MPI_Bcast
    MPI_Barrier(MPI_COMM_WORLD);
    total_mpi_bcast_time -= MPI_Wtime();
    MPI_Bcast(data, num_elements, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    total_mpi_bcast_time += MPI_Wtime();
	// Start performing 'm' operations 
	for (int i=0; i<m; i++) 
	{ 
		// Store lower and upper index i.e. range 
		int lowerbound = a[i]; 
		int upperbound = b[i]; 

		// Add k to the lower_bound 
		arr[lowerbound] += k[i]; 

		// Reduce upper_bound+1 indexed value by k 
		arr[upperbound+1] -= k[i]; 
	} 

	// Find maximum sum possible from all values 
	long long sum = 0, res = INT_MIN; 
	for (int i=0; i < n; ++i) 
	{ 
		sum += arr[i]; 
		res = max(res, sum); 
	} 

	// return maximum value 
	return res; 
} 

// Driver code 
int main() 
{ 
	// Number of values 
	int n = 5; 

	int a[] = {0, 1, 2}; 
	int b[] = {1, 4, 3}; 
	int k[] = {100, 100, 100}; 

	// m is number of operations. 
	int m = sizeof(a)/sizeof(a[0]); 

	cout << "Maximum value after 'm' operations is "
		<< findMax(n, m, a, b, k); 
	return 0; 
} 
