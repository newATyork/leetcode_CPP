class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> result;
		string ans;
		dfs( s, result, ans, 0, 0, 0 );
		return result;
	}
	void dfs( string s, vector<string>& vec, string& ans, int cnt, int depth, int sum )
	{
		if( depth == s.size() && sum <= 255 && cnt == 3 )
		{
			vec.push_back( ans );
			return;
		}
		if( sum > 255 ) return;
		if( cnt > 3 ) return;
		//  add a "."
		if( sum != 0 )
		{
			ans = ans + '.';
			dfs( s, vec, ans, cnt + 1, depth, 0 );
			ans = ans.substr( 0, ans.size() - 2 );
		}
		//  do not add "."
		if( sum <= 255 )
		{
			ans = ans + s[depth];
			sum = sum * 10 + (s[depth] - '0');
			dfs( s, vec, ans, cnt, depth + 1, sum );
            ans = ans.substr( 0, ans.size() - 2 );
		}
	}
};

