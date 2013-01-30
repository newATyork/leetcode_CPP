class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int m = matrix.size();
		int n = matrix[0].size();
		if( target < matrix[0][0] ) return false;
		if( target > matrix[m-1][n-1] ) return false;
		int start = 0;
		int end = m * n - 1;
		while( start <= end )
		{
			int mid = ( start + end ) / 2;
			int i = mid / n;
			int j = mid % n;
			if( matrix[i][j] == target ) return true;
			else if( matrix[i][j] < target ) start = mid + 1;
			else if( matrix[i][j] > target ) end = mid - 1;
		}
		return false;
	}
};

