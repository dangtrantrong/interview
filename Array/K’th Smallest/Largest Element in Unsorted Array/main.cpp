// C++ program to find K'th smallest element
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Function to return K'th smallest element in a given array
int kthSmallest(int arr[], int N, int K)
{
	// Sort the given array
	sort(arr, arr + N);

	// Return k'th element in the sorted array
	return arr[K - 1];
}

int kthSmallest(int arr[], int N, int K)
{
    // Create a max heap (priority queue)
    priority_queue<int> pq;
 
    // Iterate through the array elements
    for (int i = 0; i < N; i++) {
        // Push the current element onto the max heap
        pq.push(arr[i]);
 
        // If the size of the max heap exceeds K, remove the largest element
        if (pq.size() > K)
            pq.pop();
    }
 
    // Return the Kth smallest element (top of the max heap)
    return pq.top();
}

// Driver's code
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 2;

	// Function call
	cout << "K'th smallest element is "
		<< kthSmallest(arr, N, K);
	return 0;
}
