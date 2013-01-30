class Solution {
public:
	int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( A == NULL ) return 0;
		if( n <= 2 ) return n;
		int cnt = 1;
		int num = A[0];
		for( int i = 1; i < n; ++i )
		{
			if( A[i] == num ) cnt++;
			else if( A[i] != num )
			{
				num = A[i];
				cnt = 1;
			}
			if( cnt > 2 ) A[i] = INT_MIN;
		}
		int len = 2;
		for( int i = 2; i < n; ++i )
		{
			if( A[i] != INT_MIN )
				A[len++] = A[i];
		}
		return len;
	}
};
