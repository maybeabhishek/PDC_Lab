// C++ implementation of simple approach to 
// find maximum value after m range increments. 
#include <iostream>
using namespace std; 

// Function to find the maximum element after 
// m operations 
int findMax(int n, int a[], int b[], int k[], int m) 
{ 
	int arr[n]; 
	memset(arr, 0, sizeof(arr)); 

	// start performing m operations 
	for (int i = 0; i< m; i++) 
	{ 
		// Store lower and upper index i.e. range 
		int lowerbound = a[i]; 
		int upperbound = b[i]; 

		// Add 'k[i]' value at this operation to 
		// whole range 
		for (int j=lowerbound; j<=upperbound; j++) 
			arr[j] += k[i]; 
	} 

	// Find maximum value after all operations and 
	// return 
	int res = INT_MIN; 
	for (int i=0; i<n; i++) 
		res = max(res, arr[i]); 

	return res; 
} 

// Driver code 
int main() 
{ 
	// Number of values 
	int n = 5; 
	int a[] = {0, 1, 2}; 
	int b[] = {1, 4, 3}; 

	// value of k to be added at each operation 
	int k[] = {100, 100, 100}; 

	int m = sizeof(a)/sizeof(a[0]); 

	cout << "Maximum value after 'm' operations is "
		<< findMax(n, a, b, k, m); 
	return 0; 
} 
