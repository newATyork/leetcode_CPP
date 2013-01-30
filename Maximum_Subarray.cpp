class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int maxsum = 0;
		int sum = 0;
        int max = 0x80000000;
		for( int i = 0; i < n; ++i )
		{
			sum += A[i];
            if( A[i] > max ) max = A[i];
			if( sum > maxsum ) maxsum = sum;
			if( sum < 0 ) sum = 0;
		}
        if( max < 0 ) return max;
        return maxsum;
    }
};

