#include <iostream>
using namespace std;


class Solution {
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		bool visit[n+1];
		for( int i = 0; i < n; ++i )
			visit[i] = false;
		visit[0] = true;
		for( int i = 0; i < n - 1; ++i )
		{
			if( visit[i] == true )
			{
				int step = A[i];
				for( int j = 1; j <= step; ++j )
					visit[i+j] = true;
			}
		}
		return visit[n-1];
	}
};

class Solution2 {
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i=0;
		int m=0;
		while (i<=m) {
			m = max(m, i+A[i]);
			if (m>=n-1) break;
			i++;
		}
		if( m >= n - 1 ) 
			return true;
		return false;
	}
};

int main()
{
	int arr[] = { 3, 2, 1, 1, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Solution so;
	cout << so.canJump( arr, len ) << endl;
	return 0;
}
