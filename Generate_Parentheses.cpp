#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis( int n ) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function 
		vector<string> vec;
		string str;
		dfs( n, 1, 0, str, vec );
		return vec;
	}
	void dfs( int n, int depth, int curleft, string& str, vector<string>& vec )
	{
		if( depth > 2 * n && curleft == 0 )
		{
			vec.push_back( str );
			return;
		}
		if( depth > 2 * n ) return;
		//  add a left Parenthesis
		if( curleft < n )
		{
			str.push_back( '(' );
			dfs( n, depth + 1, curleft + 1, str, vec );
			str = str.substr( 0 , str.length()-1 );
		}
		//  add a right Parenthesis
		if( curleft > 0 )
		{
			str.push_back( ')' );
			dfs( n, depth + 1, curleft - 1, str, vec );
			str = str.substr( 0 , str.length()-1 );
		}
	}
};

int main()
{
	Solution so;
	vector<string> vec = so.generateParenthesis( 2 );
	for( int i = 0; i < vec.size(); ++i )
		cout << vec[i] << endl;
	return 0;
}
