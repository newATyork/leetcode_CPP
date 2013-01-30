#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<int> > result;
		vector<int> vec;
		dfs( n, k, 1, 1, result, vec );
		return result;
	}
	void dfs( int n, int k, int cur, int depth, vector< vector<int> >& result, vector<int>& vec )
	{
		if( depth > k )
		{
			result.push_back( vec );
			return;
		}
		if( cur > n )
			return;
		//	get this element
		vec.push_back( cur );
		dfs( n, k, cur+1, depth+1, result, vec );
		vec.pop_back();
		//	discard this element
		dfs( n, k, cur+1, depth, result, vec );
	}
};

/*
void dfs( int n, int k, int cur, int depth, vector< vector<int> >& result, vector<int>& vec )
{
	if( depth > k )
	{
		result.push_back( vec );
		return;
	}
	if( cur > n )
		return;
	//	get this element
	vec.push_back( cur );
	dfs( n, k, cur+1, depth+1, result, vec );
	vec.pop_back();
	//	discard this element
	dfs( n, k, cur+1, depth, result, vec );
}
*/

int main()
{
	
	vector< vector<int> > result;
	vector<int> vec;
	Solution s;
	result = s.combine( 2, 1 );
	for( int i = 0 ; i < result.size(); ++i )
	{
		vector<int> vec = result[i];
		for( int j = 0; j < vec.size(); ++j )
			cout << vec[j] << " ";
		cout << endl;
	}
//	dfs( 2, 1, 1, 1, result, vec );
	return 0;
}
