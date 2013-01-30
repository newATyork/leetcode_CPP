class Solution {
public:
    int romanToInt(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int result = 0;
		map< char, int > R2Imap;
		R2Imap['I'] = 1;
		R2Imap['V'] = 5;
		R2Imap['X'] = 10;
		R2Imap['L'] = 50;
		R2Imap['C'] = 100;
		R2Imap['D'] = 500;
		R2Imap['M'] = 1000;
		int i;
		for( i = 0; i < s.size() - 1; ++i )
		{
			if( R2Imap[s[i]] < R2Imap[s[i+1]] ) result -= R2Imap[s[i]];
			else result += R2Imap[s[i]];
		}
		result += R2Imap[s[i]];
		return result;
	}
};

