#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int depth = digits.length();
		vector<string> result;
		string str;
		vector<string> table;
		table.push_back("");
		table.push_back("");
		table.push_back("abc");
		table.push_back("def");
		table.push_back("ghi");
		table.push_back("jkl");
		table.push_back("mno");
		table.push_back("qprs");
		table.push_back("tuv");
		table.push_back("wxyz");
		dfs( digits, 0, str, result, table );
		return result;
	}
	void dfs( string& digits, int depth, string& str, vector<string>& result, vector<string>& table )
	{
		if( depth >= digits.length() )
		{
			result.push_back( str );
			return;
		}
		int index = digits[depth] - '0';
		for( int i = 0; i < table[index].length(); ++i )
		{
			str.push_back( table[index][i] );
			dfs( digits, depth + 1, str, result, table );
			str = str.substr( 0, str.length() - 1 );
		}
	}
};

int main()
{
	Solution so;
	vector<string> result = so.letterCombinations( "23" );
	for( int i = 0 ; i < result.size(); ++i )
		cout << result[i] << endl;
	return 0;
}
