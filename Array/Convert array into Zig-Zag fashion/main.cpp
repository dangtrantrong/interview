#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <unistd.h>

using namespace std;

void zigZag(int arr[], int n) {
    for(int i=0;i<n;i++){
        if(i%2==1){
            if(arr[i]<arr[i-1]) 
                swap(arr[i],arr[i-1]);
               
            if(arr[i]<arr[i+1]) 
                swap(arr[i],arr[i+1]);
        }
    }
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    zigZag(arr, 7);
    for (int arr_i = 0; arr_i < 7; arr_i++) {
        cout << arr[arr_i] << " ";
    }
    cout << endl;
    return 0;
}