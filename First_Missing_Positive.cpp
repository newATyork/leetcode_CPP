class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		sort( A, A + n );
        bool flag = false;
		int result = -1;
		for( int i = 0; i < n; ++i )
		{
			if( flag == false )
			{
				if( A[i] == 1 )
					flag = true;
			}
			else if( flag == true )
			{
				if( A[i] == A[i-1] )
					continue;
				if( A[i] != A[i-1] + 1 )
					return (A[i-1] + 1);
			}
		}
		if( flag == false ) return 1;
		return A[n-1] + 1;
	}
};
