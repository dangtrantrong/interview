#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
	vector<int>ans;
	
	int rowStart = 0;
	int rowEnd = r-1;
	int colStart = 0;
	int colEnd = c-1;
	
	int count = 0;
	int totalSize = r*c;
	while(count < totalSize){
		// 1st Row Print :
		for(int i=rowStart; i<=colEnd && count < totalSize; i++){
			ans.push_back(matrix[rowStart][i]);
			count++;
		}
		rowStart++;
		// last Column Print :
		for(int i=rowStart; i<=rowEnd && count < totalSize; i++){
			ans.push_back(matrix[i][colEnd]);
			count++;
		}
		colEnd--;
		// last Row Print :
		for(int i=colEnd; i>=colStart && count < totalSize; i--){
			ans.push_back(matrix[rowEnd][i]);
			count++;
		}
		rowEnd--;
		// 1st Column Print :
		for(int i=rowEnd; i>=rowStart && count < totalSize; i--){
			ans.push_back(matrix[i][colStart]);
			count++;
		}
		colStart++;
	}
	return ans;
}

int main() {
    
}