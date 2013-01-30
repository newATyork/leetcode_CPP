//  通项公式: c(2n, n)/(n+1) ???

class Solution {
public:
    int numTrees(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( n == 1 ) return 1;
		vector<int> count;
		count.push_back( 1 );
		count.push_back( 1 );
		for( int index = 2; index <= n; ++index )
		{
			int sum = 0;
			for( int i = 0; i < index; ++i )
				sum += count[i] * count[index-1-i];
			count.push_back(sum);
		}
		return count[n];
	}
};
