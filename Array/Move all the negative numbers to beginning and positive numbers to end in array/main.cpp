#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void moveArrayNegativeAndPositive(int arr[], int n)
{
    int begin = 0, end = n - 1;
    while (begin <= end) {
        if (arr[begin] > 0 && arr[end] < 0) {
            swap(arr[begin++], arr[end--]);
        } else if (arr[begin] < 0 && arr[end] > 0) {
            begin++;
            end--;
        } else if (arr[begin] < 0 && arr[end] < 0) {
            begin++;
        } else {
            end--;
        }
    }
}

void reArrange(int arr[],int n){ 
      int low =0,high = n-1; 
      while(low<high){ 
      if(arr[low]<0){ 
          low++; 
      }else if(arr[high]>0){ 
          high--; 
      }else{ 
        swap(arr[low],arr[high]); 
      } 
    } 
} 

int main() {
    int n = 6;
    int arr[] = {-1, 2, 4, -3, 6, -8};
    
    reArrange(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}