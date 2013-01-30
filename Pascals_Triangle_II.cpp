#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> result( rowIndex + 1 );
		vector<int> prerow( rowIndex + 1 );
		for( int i = 0; i <= rowIndex; ++i )
		{
			for( int j = 0; j <= i; ++j )
			{
				if( i == j ) 
					result[j] = 1;
				else if( j == 0 )
					result[j] = 1;
				else
					result[j] = prerow[j] + prerow[j-1];
			}
			prerow = result;
		}
		return result;
	}
};

int main()
{
	Solution so;
	vector<int> result = so.getRow(2);
	for( int i = 0 ; i < result.size(); ++i )
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
