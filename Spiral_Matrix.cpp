class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> result;
		vector< vector<int> > dirvec;
		vector< vector<bool> > visit;
		if( matrix.size() == 0 )
			return result;
		int arr[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
		for( int i = 0; i < 4; ++i )
		{
			vector<int> tmp;
			for( int j = 0; j < 2; ++j )
				tmp.push_back( arr[i][j] );
			dirvec.push_back( tmp );
		}
		int m = matrix.size();
		int n = matrix[0].size();
		for( int i = 0; i < m; ++i )
		{
			vector<bool> tmp;
			for( int j = 0; j < n; ++j )
				tmp.push_back(false);
			visit.push_back( tmp );
		}
		dfs( matrix, result, dirvec, visit, 0, 0, 0 );
		return result;
	}
	
	void dfs( vector< vector<int> >& matrix,  vector<int>& result, 
		vector< vector<int> >& dirvec, vector< vector<bool> >& visit,
		int x, int y, int dir )
	{
		result.push_back( matrix[x][y] );
		visit[x][y] = true;
		if( result.size() == matrix.size() * matrix[0].size() )
			return ;
		int cx = x + dirvec[dir][0];
		int cy = y + dirvec[dir][1];
		if( cx >= 0 && cx < matrix.size() 
			&& cy >= 0 && cy < matrix[0].size() 
			&& visit[cx][cy] == false )
		{
			dfs( matrix, result, dirvec, visit,  cx, cy, dir );
		}
		else
		{
			dir = ( dir + 1 ) % 4;
			cx = x + dirvec[dir][0];
			cy = y + dirvec[dir][1];
			dfs( matrix, result, dirvec, visit, cx, cy, dir );
		}
	}
};
