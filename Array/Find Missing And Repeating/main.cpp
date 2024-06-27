#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void printTwoElements1(int arr[], int n)
{
    int temp[7] = {0}; // Creating temp array of size n with
                      // initial values as 0.
    int repeatingNumber = -1;
    int missingNumber = -1;
   
    for (int i = 0; i < n; i++) {
        temp[arr[i]-1]++;
        if (temp[arr[i] - 1] > 1) {
            repeatingNumber = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (temp[i] == 0) {
            missingNumber = i + 1;
            break;
        }
    }
   
    cout << "The repeating number is " << repeatingNumber<<"."
         << endl;
    cout << "The missing number is " << missingNumber<<"."
         << endl;
   
}

void printTwoElements(int arr[], int size)
{
    int i;
    cout << "The repeating element is ";
 
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << arr[i] << "\n";
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
 
    cout << "\nand the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {1, 2, 2};
    printTwoElements(arr, 3);
    return 0;
}