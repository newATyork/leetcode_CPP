class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = matrix[0].size();
		vector< vector<int> > result;
		vector<int> tmp(n);
		for( int i = 0; i < n; ++i )
			result.push_back( tmp );
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < n; ++j )
				result[i][j] = matrix[n-1-j][i];
		matrix = result;
	}
};

