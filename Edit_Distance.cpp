#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len1 = word1.size();
		int len2 = word2.size();
		int matrix[len1+1][len2+1];
		for( int i = 0; i <= len1; ++i )
			matrix[i][0] = i;
		for( int i = 0; i <= len2; ++i )
			matrix[0][i] = i;
		for (int i = 1; i <= len1; ++i )
		{
			for (int j = 1; j <= len2; ++j )
			{
				int dist = matrix[i-1][j-1] + ( word1[i-1] != word2[j-1] );
				int tmp1 = matrix[i-1][j] + 1;
				dist = dist < tmp1 ? dist : tmp1;
				int tmp2 = matrix[i][j-1] + 1;
				dist = dist < tmp2 ? dist : tmp2;
				matrix[i][j] = dist;
			}
		}
		return matrix[len1][len2];
	}
};

class Solution1{
public:
	int minDistance(string word1, string word2)
	{
		int len1 = word1.size();
		int len2 = word2.size();
		return minDistance( word1, len1-1, word2, len2-1 );
	}
	int minDistance( string& word1, int i, string& word2, int j )
	{
		if( i < 0 && j < 0 ) return 0;
		else if( i < 0 && j >= 0 ) return j+1;
		else if( i >= 0 && j < 0 ) return i+1;
		int tmp1 = minDistance( word1, i-1, word2, j-1 ) + (word1[i] != word2[j]);
		int tmp2 = minDistance( word1, i-1, word2, j ) + 1;
		int tmp3 = minDistance( word1, i, word2, j-1 ) + 1;
		return min( tmp1, min( tmp2, tmp3 ) );
	}
};


int main()
{
	Solution so;
	int ans = so.minDistance( "iam", "ami" );
	cout << ans << endl;
	return 0;
}
