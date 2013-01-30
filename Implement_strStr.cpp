#include <iostream>
using namespace std;

class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len_needle = strlen( needle );
		int len_haystack = strlen( haystack );
		int next[ 1000 ];
		getnext( needle, len_needle, next );
		int i = 0;
		int j = 0;
		cout << endl;
		while( i < len_haystack && j < len_needle )
		{
			if( haystack[i] == needle[j] )
			{
				i++;j++;
			}
			else if( j == 0 ) i++;
			else if( j != 0 ) j = next[j-1] + 1;
		}
		if( j == len_needle )
			return haystack + i - j;
		return NULL;
	}
	void getnext( char* pattern, int len, int* next )
	{
		int index;
		next[0] = -1;
		for( int i = 1; i < len; ++i )
		{
			index = next[i-1];
			while( index >= 0 && pattern[i] != pattern[index+1] )
				index = next[index];
			if( pattern[i] == pattern[index+1] )
				next[i] = index + 1;
			else
				next[i] = -1;
		}
	}
	int strlen( char* str )
	{
		char* pch = str;
		int len = 0;
		while( *pch != '\0' )
		{
			pch++;
			len++;
		}
		return len;
	}
};

int main()
{
	char text[] = "banananobanopnanonanonanonpppnaonanano";
	char pattern[] = "banop";
	Solution so;
	char* ans = so.strStr( text, pattern );
	cout << ans << endl;
	return 0;
}
