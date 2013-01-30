class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<bool> > row( 9, vector<bool>( 10, false ) );
		vector< vector<bool> > col( 9, vector<bool>( 10, false ) );
		vector< vector<bool> > cub( 9, vector<bool>( 10, false ) );
		for( int i = 0; i < board.size(); ++i )
			for( int j = 0; j < board[0].size(); ++j )
			{
				if( board[i][j] == '.' )
					continue;
				int num = board[i][j] - '0';
				if( false == row[i][num] )
					row[i][num] = true;
				else return false;
				if( false == col[j][num] ) 
					col[j][num] = true;
				else return false;
				int cubindex = i / 3 * 3 + j / 3;
				if( false == cub[cubindex][num] )
					cub[cubindex][num] = true;
				else return false;
			}
		return true;
	}
};
