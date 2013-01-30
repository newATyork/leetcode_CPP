#include <iostream>
using namespace std;

//	TLE on the large test
class Solution {
public:
	int jump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int dp[n];
		for( int i = 0; i < n; ++i )
			dp[i] = 0x7FFFFFFF;
		dp[0] = 0;
		for( int i = 0; i < n - 1; ++i )
		{
			if( dp[i] == 0x7FFFFFFF ) continue;
			int maxstep = A[i];
			for( int j = 1; j <= maxstep; ++j )
			{
				int step = dp[i] + 1;
				if( step < dp[i+j] )
					dp[i+j] = step;
			}
		}
		return dp[n-1];
	}
};

class Solution {
public:
	int jump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int jump = 0;
		int i = 0;
		int curmax = 0;
		while( i < n - 1 )
		{
			curmax = i + A[i];
			jump++;
			if( curmax >= n - 1 )
				return jump;
			int tmpmax = 0;
			for( int j = i + 1; j <= curmax; ++j )
			{
				if( j + A[j] > tmpmax )
				{
					tmpmax = j + A[j];
					i = j;
				}
			}
		}
		return jump;
	}
};


int main()
{
	int arr[] = { 2, 3, 1, 1, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Solution so;
	cout << so.jump( arr, len ) << endl;
	return 0;
}
