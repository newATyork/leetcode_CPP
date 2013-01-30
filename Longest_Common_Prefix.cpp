#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( strs.size() == 0 )
			return "";
		string result = "";
		char cur;
		int index = 0;
		int i, j;
		bool flag = false;
		while( true )
		{
			if( index >= strs[0].length() )
			{
				flag = true;
				break;
			}
			cur = strs[0][index];
			for( i = 1; i < strs.size(); ++i )
			{
				if( index >= strs[i].length() )
				{
					flag = true;
					break;
				}
				if( strs[i][index] != cur )
				{
					flag = true;
					break;
				}
			}
			if( flag == true ) break;
			result += cur;
			index++;
		}
		return result;
	}
};

class Solution{
public:
	string longestCommonPrefix(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		string result = strs[0];
		for( int i = 1; i < strs.size(); ++i )
			for( int j = 0; j < result.size(); ++j )
			{
				if( j >= strs[i].length() )
				{
					result = result.substr( 0, j );
					break;
				}
				if( strs[i][j] != result[j] )
				{
					result = result.substr( 0, j );
					break;
				}
			}
		return result;
	}	
};

int main()
{
	Solution so;
	return 0;
}
