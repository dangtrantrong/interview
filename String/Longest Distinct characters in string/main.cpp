#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

int longestSubstrDistinctCharsMethodOne(string str)
{
	// if string length is 0
    if (str.length() == 0)
        return 0;
 
    // if string length 1
    if (str.length() == 1)
        return 1;
 
    // if string length is more than 2
    int maxLength = 0;
    bool visited[256] = { false };
 
    // left and right pointer of sliding window
    int left = 0, right = 0;
    while (right < str.length()) {
 
        // if character is visited
        if (visited[str[right]] == true) {
 
            // The left pointer moves to the right while
            // marking visited characters as false until the
            // repeating character is no longer part of the
            // current window.
            while (visited[str[right]] == true) {
 
                visited[str[left]] = false;
                left++;
            }
        }
 
        visited[str[right]] = true;
 
        // The length of the current window (right - left +
        // 1) is calculated and answer is updated
        // accordingly.
        maxLength = max(maxLength, (right - left + 1));
		cout << "S[i]: " << str[right] << "\n";
		cout << "right: " << right << "\n";
		cout << "left: " << left << "\n";
		cout << "maxlenght: " << maxLength << "\n";
		cout << "-----------------------\n";
        right++;
    }
    return maxLength;
}

int longestSubstrDistinctChars(string str) {
	int result = 0;
	map<char, int> lastVisited;
	for (int start = 0, end = 0; end < str.size(); end++)
	{
		if (lastVisited.count(str[end])) {
			start = max(start, lastVisited[str[end]] + 1);
		}
		result = max(result, end - start + 1);
		lastVisited[str[end]] = end;
	}
	return result;
}