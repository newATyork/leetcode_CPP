class Solution {
public:
	bool isValid(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int big = 0, mid = 0, small = 0;
		for( int i = 0; i < s.size(); ++i )
		{
			if( '(' == s[i] ) small++;
			else if( '[' == s[i] ) mid++;
			else if( '{' == s[i] ) big++;
			else if( ')' == s[i] ) small--;
			else if( ']' == s[i] ) mid--;
			else if( '}' == s[i] ) big--;
			if( small < 0 || mid < 0 || big < 0 )
				return false;
		}
		if( 0 == small && 0 == mid && 0 == big  )
			return true;
		return false;
	}
};
