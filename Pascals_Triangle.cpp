#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<int> > result;
		for( int i = 0; i < numRows; ++i )
		{
			vector<int> row;
			for( int j = 0; j <= i; ++j )
			{
				if( j == i )
					row.push_back(1);
				else if( j == 0 )
					row.push_back(1);
				else
					row.push_back( result[i-1][j] + result[i-1][j-1] );
			}
			result.push_back(row);
		}
		return result;
	}
};

int main()
{
	Solution so;
	vector< vector<int> > result = so.generate(3);
	for( int i = 0; i < result.size(); ++i )
	{
		for( int j = 0; j < result[i].size(); ++j )
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}
