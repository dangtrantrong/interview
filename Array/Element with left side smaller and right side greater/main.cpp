#include <iostream>
using namespace std;
 
//Function to check
bool check(int arr[], int n,int ind){
    int i=ind-1;
    int j=ind+1;
     
    while(i>=0){
        if(arr[i]>arr[ind]){return false;}
        i--;
    }
     
    while(j<n){
        if(arr[j]<arr[ind]){return false;}
        j++;
    }
     
    return true;
}

 
// Function to return the index of the element which is greater than 
// all left elements and smaller than all right elements.
int findElement(int arr[], int n)
{
    
    // Traverse array from 1st to n-1 th index because
    //Extrem elements can't be aur answer
    for (int i=1; i<n-1; i++)
    {
       if(check(arr,n,i)){return i;}
    }
 
    // If there was no element matching criteria
    return -1;
}

int findElementOtherWay(int arr[], int n)
{
	// leftMax[i] stores maximum of arr[0..i-1]
	int leftMax[n];
	leftMax[0] = INT_MIN;

	// Fill leftMax[1..n-1]
	for (int i = 1; i < n; i++)
		leftMax[i] = max(leftMax[i-1], arr[i-1]);

	// Initialize minimum from right
	int rightMin = INT_MAX;

	// Traverse array from right
	for (int i=n-1; i>=0; i--)
	{
		// Check if we found a required element
		if (leftMax[i] < arr[i] && rightMin > arr[i])
			return i;

		// Update right minimum
		rightMin = min(rightMin, arr[i]);
	}

	// If there was no element matching criteria
	return -1;
}
 
// Driver program
int main()
{
    int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    int n = sizeof arr / sizeof arr[0];
    cout << "Index of the element is " << findElementOtherWay(arr, n);
    return 0;
}