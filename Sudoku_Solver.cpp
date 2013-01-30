class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<bool> > row( 9, vector<bool>( 10, false ) );
		vector< vector<bool> > col( 9, vector<bool>( 10, false ) );
		vector< vector<bool> > cub( 9, vector<bool>( 10, false ) );
		vector< vector<char> > result;
		for( int i = 0; i < board.size(); ++i )
			for( int j = 0; j < board[0].size(); ++j )
			{
				if( board[i][j] == '.' )
					continue;
				int num = board[i][j] - '0';
				row[i][num] = true;
				col[j][num] = true;
				int cubindex = i / 3 * 3 + j / 3;
				cub[cubindex][num] = true;
			}
		dfs( board, row, col, cub, 0, result );
		board = result;
	}
	void dfs( vector< vector<char> >& board, vector< vector<bool> >& row,
		vector< vector<bool> >& col, vector< vector<bool> >& cub,
		int depth, vector< vector<char> >& result )
	{
		if( depth >= 81 ) 
		{
			result = board;
			return;
		}
		int x = depth / 9;
		int y = depth % 9;
		if( board[x][y] == '.' )
		{
			for( int i = 1; i <= 9; ++i )
			{
				char digit = i + '0';
				if( row[x][i] == true ) continue;
				if( col[y][i] == true ) continue;
				int cubindex = x / 3 * 3 + y / 3;
				if( cub[cubindex][i] == true ) continue;
				board[x][y] = digit;
				row[x][i] = true;
				col[y][i] = true;
				cub[cubindex][i] = true;
				dfs( board, row, col, cub, depth + 1, result );
				board[x][y] = '.';
				row[x][i] = false;
				col[y][i] = false;
				cub[cubindex][i] = false;
			}
		}
		else
			dfs( board, row, col, cub, depth + 1, result );
	}
};
