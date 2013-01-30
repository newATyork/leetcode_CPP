#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
			int max = -1;
			int cur = 0;
			for( int i = 0; i < s.length(); ++i )
			{
				if( s[i] == '(' )
					cur = validLength( s.substr( i, s.length()-1 ) );
				if( cur > max )
					max = cur;
			}
			return max;
	}
	int validLength( string s )
	{	
		int len = s.length();
		if( len == 0 ) return 0;
		int max = 0;
		int start = 0;
		int leftp = 0;
		for( int i = 0; i < len; ++i )
		{
			if( s[i] == '(' )
			{
				if( leftp < 0 )
				{
					start = i;
					leftp = 0;
				}
				leftp++;
			}
			else if( s[i] == ')' )
			{
				leftp--;
			}
			if( leftp == 0 )
			{
				int curlen = i - start + 1;
				if( curlen > max ) max = curlen;
			}
		}
		return max;
	}
};




int main()
{
	Solution so;
	int ans = so.longestValidParentheses( ")(((((()())()()))()(()))(" );
	cout << ans << endl;
	return 0;
}
