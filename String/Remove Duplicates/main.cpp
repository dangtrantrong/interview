#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

string removeDups(string S) 
{
	map<char, int> mapStr;
	string output;
	for (int i = 0; i < S.size(); i++)
	{
		mapStr[S[i]]++;
		if (mapStr[S[i]] == 1) {
			output += S[i];
		}
	}

	return output;
}