class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<int> > result;
		vector<int> rec;
		dfs( S, result, rec, 0 );
		for( int i = 0; i < result.size(); ++i )
			sort( result[i].begin(), result[i].end() );
		return result;
	}
	void dfs( vector<int>& s, vector< vector<int> >& result, vector<int>& rec, int depth )
	{
		if( depth == s.size() )
		{
			result.push_back(rec);
			return;
		}
		//  discard this element
		dfs( s, result, rec, depth + 1 );
		//  get this element
		rec.push_back( s[depth] );
		dfs( s, result, rec, depth + 1 );
		rec.pop_back();
	}
};
