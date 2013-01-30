class Solution {
public:
	string convert(string s, int nRows) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( 1 == nRows ) return s;
		vector< string > zig(nRows);
		bool dir = true;
		int index = 0;
		for( int i = 0; i < s.size(); ++i )
		{
			zig[index].push_back(s[i]);
			if( index == nRows - 1 ) dir = false;
			else if( index == 0 ) dir = true;
			if( true == dir ) index++;
			else if( false == dir ) index--;
		}
		string result;
		for( int i = 0; i < nRows; ++i )
			result += zig[i];
		return result;
	}
};
