class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( 0 == grid.size() )
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		for( int i = 0; i < grid.size(); ++i )
		{
			for( int j = 0; j < grid[i].size(); ++j )
			{
				int up, left;
				if( i == 0 && j == 0 ) continue;
				up = ( 0 == i ) ? 0x7FFFFFFF : grid[i-1][j];
				left = ( 0 == j ) ? 0x7FFFFFFF : grid[i][j-1];
				grid[i][j] = min( up, left ) + grid[i][j];
			}
		}
		return grid[m-1][n-1];
	}
};

