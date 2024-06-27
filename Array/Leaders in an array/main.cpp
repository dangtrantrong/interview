#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

vector<int> leaders(int a[], int n){
    // Code here
    stack<int> stackElements;
    vector<int> output;
    int max = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= max) {
            cout << "a[i]: " << a[i] << endl;
            stackElements.push(a[i]);
            max = a[i];
        }
    }

    while (!stackElements.empty())
    {
        output.push_back(stackElements.top());
        stackElements.pop();
    }
    return output;
    
}

int main() {
    
    int a[] = {1,2,3,4,0};
    
    vector<int> output = leaders(a, 5);
    for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}