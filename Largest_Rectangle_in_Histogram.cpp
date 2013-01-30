#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int right = 0;
		int left = 0;
		int max = 0;
		int area = 0;
		while( right < height.size() )
		{
			right = findright( height, right );
			for( int i = left; i < right; ++i )
			{
				area = min( height[right], height[i] ) * ( right - i + 1 ) ;
				if( area > max ) max = area;
			}
			left = right + 1;
		}

		return max;	
	}
	int findright( vector<int>& height, int start )
	{
		if( start == height.size() - 1 )
			return start;
		for( int i = start + 1; i < height.size(); ++i )
		{
			if( i == height.size() - 1 )
				return i;
			if( height[i+1] < height[i] )
				return i;
		}
	}
};


int min( int a, int b )
{
	return a < b ? a : b;
}

int main()
{
	Solution so;
	int arr[] = { 6, 10, 14, 12, 8, 13 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int> vec;
	for( int i = 0; i < len; ++i )
		vec.push_back(arr[i]);
	cout << so.largestRectangleArea( vec ) << endl;
//	cout << ans << endl;
	return 0;
}
