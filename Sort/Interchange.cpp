#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void InterchangeSort(int a[], int n){	
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
	        if(a[i] > a[j])  //nếu có nghịch thế thì đổi chỗ
		        Swap(a[i], a[j]);
}

int main() {
    int a[] = {1, 5, 4, 3, 2, 7, 8, 9}; 
    InterchangeSort(a, 8);
    for (int i = 0; i < 8; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}