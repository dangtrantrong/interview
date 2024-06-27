#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

string reverseWords(string S) 
{ 
    string res = "";
    stack<string> stackWords;
    string word = "";
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '.')
        {
            stackWords.push(word);
            stackWords.push(".");
            word = "";
        } else {
            word.push_back(S[i]);
        }
    }
    stackWords.push(word);

    while (!stackWords.empty())
    {
        cout << stackWords.top() << endl;
        res += stackWords.top();
        stackWords.pop();
    }
    return res;
} 

int main() {
    cout << reverseWords("hello.world") << endl;
    return 0;
}