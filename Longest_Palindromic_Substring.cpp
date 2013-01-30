
//	寻找一个字符串的最长回文子串

//	Solution:
//	1.	Brute force solution: O(n^3). pick all possible starting position and ending position. determine if it is a palindrome.
//	2.	DP O(n^2) time and O(n^2) space. Define p[i][j] = true, if the substring str[i..j] is a palindrome.
//	3.	Extend from center. O(n^2) time and O(1) space. pick all position, extend its left and right border to see that if it is a palindrome.	

#include <iostream>
#include <string.h>
using namespace std;

void LPS_s1( char* str )
{
	int len = strlen(str);
	for( int i = 0 ; i < len - 1 ; ++i )
		for( int j = i + 1 ; j < len ; ++j )
		{
			int left = i;
			int right = j;
			bool flag = true;
			while( left < right )
			{
				if( str[left] == str[right] )
				{
					left++;
					right--;
				}
				else if( str[left] != str[right] )
				{
					flag = false;
					break;
				}
			}
			if( flag == true )
			{
				for( char* p = str+i ; p <= str+j ; ++p )
					cout << *p;
				cout << endl;
			}
		}
}

//	Solution 2:
//	DP, O(n^2) time and O(n^2) space
string LPS_s2( string s)
{
	int len = s.length();
	int LPSBegin = 0;
	int maxLen = 1;
	bool table[1000][1000] = {false};
	
	for( int i = 0; i < len; ++i )
		table[i][i] = true;
	
	for( int i = 0; i < len - 1; ++i )
	{
		if( s[i] == s[i+1] )
		{
			table[i][i+1] = true;
			LPSBegin = i;
			maxLen = 2;
		}
	}
	for( int l = 3; l <= len; ++l )
	{
		for( int i = 0; i < len - l + 1; ++i )
		{
			int j = i + l - 1;
			if( s[i] == s[j] && table[i+1][j-1] == true )
			{
				table[i][j] = true;
				LPSBegin = i;
				maxLen = l;
			}
		}
	}
	return s.substr( LPSBegin, maxLen );
}

string expand( string s, int c1, int c2 );

//	Solution 3:
//	O(n^2) time and O(1)space. extend from the center
string LPS_s3( string s )
{
	int len = s.length();
	string lps = s.substr( 0, 1 );
	for( int i = 0; i < len - 1; ++i )
	{
		string p1 = expand( s, i, i );
		if( p1.length() > lps.length() )
			lps = p1;
		string p2 = expand( s, i, i+1 );
		if( p2.length() > lps.length() )
			lps = p2;
	}
	return lps;
}

string expand( string s, int c1, int c2 )
{
	int left = c1;
	int right = c2;
	int len = s.length();
	while( left >= 0 && right < len && s[left] == s[right] )
	{
		left--;
		right++;
	}
	return s.substr( left + 1, right - left - 1 );
}

class Solution {
public:
	string longestPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = s.length();
		string lps = s.substr( 0, 1 );
		for( int i = 0; i < len - 1; ++i )
		{
			string p1 = expand( s, i, i );
			if( p1.length() > lps.length() )
				lps = p1;
			string p2 = expand( s, i, i + 1 );
			if( p2.length() > lps.length() )
				lps = p2;
		}
		return lps;
	}
	string expand( string s, int c1, int c2 )
	{
		int left = c1;
		int right = c2;
		int len = s.length();
		while( left >= 0 && right < len && s[left] == s[right] )
		{
			left--;
			right++;
		}
		return s.substr( left + 1, right - left - 1 );
	}
};


int main()
{
	char str[] = "abacdfgdcaba";
	//LPS_s1( str );
	string r = LPS_s3( str );
	cout << r << endl;
	return 0;
}

