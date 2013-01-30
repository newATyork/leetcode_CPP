class Solution {
public:
    int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( A == NULL || n == 0 ) 
			return 0;
		sort( A, A + n );
		int len = 1;
		for( int i = 1; i < n; ++i )
		{
			if( A[i] == A[i-1] )
				continue;
			A[len++] = A[i];
		}
		return len;
	}
};

