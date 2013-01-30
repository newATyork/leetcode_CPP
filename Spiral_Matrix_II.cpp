class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<int> > illegal;
		if( n == 0 ) return illegal;
		vector< vector<int> > result( n, vector<int>(n) );
		vector< vector<bool> > visit( n, vector<bool>(n) );
		vector< vector<int> > dir( 4, vector<int>(2) );
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < n; ++j )
			{
				result[i][j] = 0;
				visit[i][j] = false;
			}
			int arr[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
			for( int i = 0; i < 4; ++i )
				for( int j = 0; j < 2; ++j )
					dir[i][j] = arr[i][j];
			dfs( result, dir, visit, 0, 0, 0, 1 );
			return result;
	}
	void dfs( vector< vector<int> >& matrix, vector< vector<int> >& dir, 
		vector< vector<bool> >& visit, int x, int y, int curdir, int depth )
	{
		matrix[x][y] = depth;
		visit[x][y] = true;
		if( depth == matrix.size() * matrix.size()  )
			return;
		int cx = x + dir[curdir][0];
		int cy = y + dir[curdir][1];
		if( cx >= 0 && cx < matrix.size() 
			&& cy >= 0 && cy < matrix.size()
			&& visit[cx][cy] == false )
		{
			dfs( matrix, dir, visit, cx, cy, curdir, depth + 1 );
		}
		else
		{
			curdir = ( curdir + 1 ) % 4;
			cx = x + dir[curdir][0];
			cy = y + dir[curdir][1];
			dfs( matrix, dir, visit, cx, cy, curdir, depth + 1 );
		}
	}
};
