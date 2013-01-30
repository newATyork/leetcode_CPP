class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( 0 == matrix.size() ) return;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<bool> row(m);
		vector<bool> column(n);
		for( int i = 0; i < m; ++i )
			row[i] = false;
		for( int j = 0; j < n; ++j )
			column[j] = false;
		for( int i = 0; i < m; ++i )
			for( int j = 0; j < n; ++j )
				if( matrix[i][j] == 0 )
				{
					row[i] = true;
					column[j] = true;
				}
		for( int i = 0; i < m; ++i )
			for( int j = 0; j < n; ++j )
				if( row[i] || column[j] )
					matrix[i][j] = 0;
	}
};

