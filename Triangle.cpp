class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		for( int i = 1; i < triangle.size(); ++i )
		{
			for( int j = 0; j <= i; ++j )
			{
				if( j == i ) triangle[i][j] += triangle[i-1][j-1];
				else if( j == 0 ) triangle[i][j] += triangle[i-1][j];
				else triangle[i][j] += min( triangle[i-1][j-1], triangle[i-1][j] );
			}
		}
		int min = INT_MAX;
		int lastrow = triangle.size() - 1;
		int len = triangle[lastrow].size();
		for( int i = 0; i < len; ++i )
			if( triangle[lastrow][i] < min )
				min = triangle[lastrow][i];
		return min;
	}
};
