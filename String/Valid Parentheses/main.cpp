#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

bool isValid(string s) {
    stack<char> st; 

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch); 
        } else if (!st.empty()) {
            char top = st.top(); 

            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')) {

                    st.pop(); 
            } else {
                return false; 
            }  
        } else { // stack is empty and we get a closing bracket means the string is unbalanced 
            return false; 
        }   

    }

    // in the end if the stack is empty -- meaning there is no opening bracket present in the stack -- meaning all opening brackets have found their corresponding closing bracket and have been popped then we return true  
    return st.empty();  

}  