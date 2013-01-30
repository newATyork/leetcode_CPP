#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<int> > result;
		permutation( num, result, 0 );
        sort( result.begin(), result.end() );
        result.erase( unique(result.begin(), result.end() ), result.end() );
		return result;
	}
	void permutation( vector<int>& num, vector< vector<int> >& result, int depth )
	{
		if( depth == num.size() )
		{
			result.push_back( num );
			return;
		}
		for( int i = depth; i < num.size(); ++i )
		{
			swap( num[i], num[depth] );
			permutation( num, result, depth + 1 );
			swap( num[i], num[depth] );
		}
	}
};

int main()
{
	Solution so;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(1);
	vector<vector<int> > vec2d = so.permute( vec );
	for( int i = 0; i < vec2d.size(); ++i )
	{
		for( int j = 0; j < vec2d[i].size(); ++j )
			cout << vec2d[i][j];
		cout << endl;
	}
	return 0;
}
