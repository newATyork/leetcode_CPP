
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

vector< vector<int> > result;

void output( vector<int>& vec )
{
	for( int i = 0; i < vec.size(); ++i )
		cout << vec[i] << " ";
	cout << endl;
}


void dfs( vector<int> arr, int target, int depth, int sum, vector<int>& vec, vector< vector<int> >& result )
{
	if( sum == target )
	{
		result.push_back( vec );
		return;
	}
	if( sum > target || depth >= arr.size() )
		return;
	vec.push_back( arr[depth] );
	dfs( arr, target, depth, sum + arr[depth], vec, result );
	vec.pop_back();
	//	add this position then move to next position
	vec.push_back( arr[depth] );
	dfs( arr, target, depth + 1, sum + arr[depth], vec, result );
	vec.pop_back();
	//	discard this position then move to next position
	dfs( arr, target, depth + 1, sum, vec, result );
}


void combination( vector<int> arr, int target )
{
	vector<int> vec;
	vector< vector<int> > result;
	dfs( arr, target, 0, 0, vec, result );
	
	vector<vector<int> >::iterator end = result.end();  
	sort(result.begin(), end, less<vector<int> >());
	vector<vector<int> >::iterator new_end = unique(result.begin(), result.end());
	result.erase(new_end, end);

	return result;
}

int main()
{
	int arr[] = { 1, 1, 2, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int> candidates;
	for( int i = 0; i < len; ++i )
		candidates.push_back( arr[i] );
	int target = 3;
	int sum = 0;
	combination( candidates, target );
	cout << "result :" << result.size() << endl;
	for( int i = 0; i < result.size(); ++i )
	{
		vector<int> tmp = result[i];
		for( int j = 0; j < tmp.size(); ++j )
			cout << tmp[j] << " ";
		cout << endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec;
        vector< vector<int> > result;
	    dfs( num, target, 0, 0, vec, result );
	    return result;
    }
    void dfs( vector<int> arr, int target, int depth, int sum, vector<int>& vec, vector< vector<int> >& result )
    {
        if( sum == target )
	    {
		    result.push_back( vec );
		    return;
	    }
	    if( sum > target || depth >= arr.size() )
		    return;
	
	    //	add this position then move to next position
	    vec.push_back( arr[depth] );
	    dfs( arr, target, depth + 1, sum + arr[depth], vec, result );
	    vec.pop_back();
	    //	discard this position then move to next position
	    dfs( arr, target, depth + 1, sum, vec, result );
    }
};
