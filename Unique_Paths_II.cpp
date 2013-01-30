class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( 1 == obstacleGrid[0][0] )
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector< vector<int> > result( m, vector<int>( n, 0 ) );
		for( int i = 0; i < m; ++i )
			for( int j = 0; j < n; ++j )
			{
				if( 1 == obstacleGrid[i][j] )
					result[i][j] = 0;
				else if( 0 == obstacleGrid[i][j] )
				{
					if( 0 == i && 0 == j ) result[i][j] = 1;
					else if( 0 == i ) result[i][j] = result[i][j-1];
					else if( 0 == j ) result[i][j] = result[i-1][j];
					else result[i][j] = result[i-1][j] + result[i][j-1];
				}
			}
		return result[m-1][n-1];
	}
};
