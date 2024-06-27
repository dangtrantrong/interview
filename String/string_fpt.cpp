#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

int atoiImplement(string s) {
	int i = 0;
	int check = 1;
	if (s[0] == '-') {
		check = -1;
		++i;
	}

	int output = 0;
	for (; i < s.size(); i++)
	{
		if (s[i] < '0' || s[i] > '9') 
			return -1;
		output = output * 10 + s[i] - '0';
	}
	
	return output * check;
}

int strstr(string s, string x) {
	for(int i = 0; i < s.size(); i++) {
		bool flag = false;
		// here is the vital part write it in your copy and dry run once
		for(int j = 0; j < x.size(); j++) {
			if(s[i+j] != x[j]) {
				flag = false;
				break;
			} else {	
				flag = true;
			}
		}
             
		if(flag == true){
			return i;
		}
     }
     return -1;
}

/* Leetcode 14*/
string longestCommonPrefix (string arr[], int n) {
	if (n == 0) {
		return "";
	}

	if (n == 1) {
		return arr[0];
	}

	sort(arr, arr + n);

	int minLenght = min(arr[0].size(), arr[n - 1].size());

	int i = 0;
	while (i < minLenght && arr[0][i] == arr[n - 1][i]) {
		++i;
	}

	return arr[0].substr(0, i);
}

string longestCommonPrefixMethodOther(string arr[], int n) {
	string result = arr[0];
	int lenght = result.length();

	for (int i = 1; i < n; i++)
	{
		while (arr[i].find(result) == std::string::npos)
		{
			result = result.substr(0, --lenght);
		}

		if (result.empty())
		{
			return "-1";
		}
	}
	return result;
	
}
/*------------*/

/*Leetcode 392. Is Subsequence*/
bool isSubsequence(string s, string t) {
    int pos = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == s[pos]) {
            ++pos;
        }
    }

    return pos == s.size();
}

/*Leetcode - 680. Valid Palindrome II*/
bool isPalindrome(string s, int left, int right)
{
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else {
            return false;
        } 
    }

    return true;
}

bool validPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    int removeCount = 0;
    while (left < right)
    {
        if (s[left] == s[right])
        {
            ++left;
            --right;
        } else {
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        
    }
    return true;
    
}
/*--------------------------------------*/

/*Leetcode - 792. Number of Matching Subsequences*/
int numMatchingSubseq(string s, vector<string> words) {
    int count = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (isSubsequence(words[i], s))
        {
            ++count;
        }
    }

    return count;
}

int main() {
    // cout << isSubsequence("abc", "ahbgdc") << "\n";

    // cout << validPalindrome("eeccccbebaeeabebccceea") << "\n";

    cout << numMatchingSubseq("dsahjpjauf", {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"}) << "\n";
}