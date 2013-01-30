class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> result;
		int start = 0;
		int end = n - 1;
		bool found = false;
		int mid;
		while( start <= end )
		{
			mid = ( start + end ) / 2;
			if( A[mid] == target )
			{
				found = true;
				break;
			}
			else if( A[mid] < target ) start = mid + 1;
			else if( A[mid] > target ) end = mid - 1;
		}
		if( false == found )
		{
			result.push_back(-1);
			result.push_back(1);
			return result;
		}
		int left = mid - 1;
		int right = mid + 1;
		while( A[left] == A[mid] ) left--;
		while( A[right] == A[mid] ) right++;
		result.push_back( left + 1 );
		result.push_back( right - 1 );
		return result;
	}
};

