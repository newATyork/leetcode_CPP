class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( target <= A[0] ) return 0;
		if( target > A[n-1] ) return n;
		int left = 0;
		int right = n - 1;
		while( left <= right )
		{
			int mid = ( left + right ) / 2;
			if( target <= A[mid] && target > A[mid-1] )
				return mid;
			else if( A[mid] < target )
				left = mid + 1;
			else if( A[mid] >= target )
				right = mid - 1;
		}
	}
};
