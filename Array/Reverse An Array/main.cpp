#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>

using namespace std;

void reverseArray(vector<int> &input) {
    for(int i = 0; i < input.size()/2; i++) {
        // std::swap(input[i], input[input.size() - i - 1]);
        int temp = input[i];
        input[i] = input[input.size() - i - 1];
        input[input.size() - i - 1] = temp;
    }
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverseArray(input);
    for(int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}