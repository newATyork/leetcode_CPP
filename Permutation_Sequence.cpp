#include <iostream>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function 
		string rec;
		for( int i = 1; i <= n; ++i  )
			rec = rec + char(i + int('0'));
		int cnt = 0;
		string result;
		permutation( rec, result, k, cnt, 0 );
		return result;
	}
	void permutation( string& rec, string& result, int k, int& cnt, int depth )
	{
		if( depth == result.size() )
		{
			cnt++;
			if( cnt == k ) 
				result = rec;
			return;
		}
		for( int i = depth; i < result.size(); ++i )
		{
			char ch = rec[depth];
			rec[depth] = rec[i];
			rec[i] = ch;
			permutation( rec, result, k, cnt, depth + 1 );
			ch = rec[depth];
			rec[depth] = rec[i];
			rec[i] = ch;
		}
	}
};


int main()
{
	Solution so;
	string str = so.getPermutation( 3, 2 );
	cout << str << endl;
	return 0;
}
