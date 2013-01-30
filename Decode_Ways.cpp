#include <iostream>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( s == "" ) return 0;
		if( s[0] == '0' ) return 0;
		int result = 1;
		int pre = 1;
		for( int i = 1; i < s.size(); ++i )
		{
			int tmp = result;
			if( s[i] == '0' ) 
				result = 0;
			if( (s[i-1]-'0')*10 + (s[i]-'0') >= 10 && (s[i-1]-'0')*10 + (s[i]-'0') <= 26 )
				result = result + pre;
			pre = tmp;
		}
		return result;
	}
};


int main()
{
	string s = "99999";
	Solution so;
	int sum = so.numDecodings( s );
	cout << sum << endl;
	return 0;
}

