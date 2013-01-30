#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int pos[256];
		int len = 0;
		int maxlen = 0;
		int cur_start = 0;
		for( int i = 0; i < 256; ++i )
			pos[i] = -1;
		for( int i = 0; i < s.length(); ++i )
		{
			if( pos[s[i]] == -1 )
			{
				pos[s[i]] = i;
				len = len + 1;
				len = len > maxlen ? len : maxlen;
			}
			else if( pos[s[i]] != -1 )
			{

			}
		}
	}
};

int main()
{
	return 0;
}
