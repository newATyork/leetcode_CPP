class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<int> > dir( 4, vector<int>(2) );
		int arrdir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
		for( int i = 0; i < 4; ++i )
			for( int j = 0; j < 2; ++j )
				dir[i][j] = arrdir[i][j];
		int m = board.size();
		int n = board[0].size();
		for( int i = 0; i < m; ++i )
			for( int j = 0; j < n; ++j )
			{
				bool flag = false;
				if( board[i][j] == word[0] )
				{
					vector< vector<bool> > visit( m, vector<bool>( n, false ) );
					flag = dfs( board, visit, dir, word, 0, i, j );
				}
				if( true == flag ) return true;
			}
		return false;
	}
	bool dfs( vector< vector<char> >& board, vector< vector<bool> >& visit,
		vector< vector<int> >& dir, string& word, int depth, int x, int y )
	{
		if( board[x][y] == word[depth] )
		{
			if( depth == word.size() - 1 ) return true;
			visit[x][y] = true;
			for( int i = 0; i < 4; ++i )
			{
				int cx = x + dir[i][0];
				int cy = y + dir[i][1];
				if( cx < 0 || cx >= board.size() ) continue;
				if( cy < 0 || cy >= board[0].size() ) continue;
				if( true == visit[cx][cy] ) continue;
				bool flag = dfs( board, visit, dir, word, depth + 1, cx, cy );
				if( true == flag ) return true;
			}
			visit[x][y] = false;
		}
		return false;
	}
};
