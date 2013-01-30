#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<string> > result;
		vector<int> rec(n);
		dfs( result, rec, n, 0 );
		return result;
	}
	void dfs( vector< vector<string> >& result, vector<int>& rec, int maxDepth, int depth )
	{
		if( depth == maxDepth )
		{
			vector<string> map;
			for( int i = 0; i < maxDepth; ++i )
			{
				string row = "";
				for( int j = 0; j < maxDepth; ++j )
				{
					char ch = ( j == rec[i] ) ? 'Q'	: '.';
					row = row + ch;
				}
				map.push_back( row );
			}
			result.push_back(map);
			return;
		}
		for( int i = 0; i < maxDepth; ++i )
		{
			if( check( rec, depth, i ) )
			{
				rec[depth] = i;
				dfs( result, rec, maxDepth, depth + 1 );
			}
		}
	}
	bool check( vector<int>& rec, int depth, int pos )
	{
		for( int i = 0; i < depth; ++i )
		{
			if( rec[i] == pos ) 
				return false;
			else if( abs(pos - rec[i]) == abs(depth - i) )
				return false;
		}
		return true;
	}
};


int main()
{
	Solution so;
	vector< vector<string> > result;
	result = so.solveNQueens(8);
	for( int i = 0; i < result.size(); ++i )
	{
		for( int j = 0; j < result[i].size(); ++j )
		{
			for( int k = 0; k < result[i][j].size(); ++k )
			{
				cout << result[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "size of answer: " << result.size() << endl;
	return 0;
}
