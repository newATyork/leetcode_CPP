class Solution {
public:
	int totalNQueens(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> rec(n);
		int cnt = 0;
		dfs( rec, n, 0, cnt );
		return cnt;
    }
    void dfs( vector<int>& rec, int maxDepth, int depth, int& cnt )
    {
		if( depth == maxDepth )
		{
		    cnt++;
			return;
		}
		for( int i = 0; i < maxDepth; ++i )
		{
			if( check( rec, depth, i ) )
			{
				rec[depth] = i;
				dfs( rec, maxDepth, depth + 1, cnt );
			}
		}
	}
	bool check( vector<int>& rec, int depth, int pos )
	{
		for( int i = 0; i < depth; ++i )
		{
			if( rec[i] == pos ) 
				return false;
			else if( abs(pos - rec[i]) == abs(depth - i) )
				return false;
		}
		return true;
	}
};

