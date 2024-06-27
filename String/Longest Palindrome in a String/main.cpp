#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

string longestPalindrome (string S) {
	int start = 0, end = 0;
    int low, high;
    
	for(int i = 0; i < S.length(); i++){
        // odd part
		low = i - 1;
		high = i;
        while(low>=0 && high<S.length() && S[low] == S[high]){
            
            if(high - low + 1 > end){
                end = high - low + 1; //current longest pallindrome length
                start = low;
            }
            low--;
            high++;
        }

        // Even part
		low = i - 1;
		high = i + 1;
        while(low>=0 && high<S.length() && S[low] == S[high]){
            
            if(high - low + 1 > end){
                end = high - low + 1; //current longest pallindrome length
                start = low;
            }
            low--;
            high++;
        }
        
    }

    if(end == 0)
		return S.substr(start,1); // no pallindrome at all
    
	return S.substr(start,end);
}