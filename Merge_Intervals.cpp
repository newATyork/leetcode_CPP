#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	class cmp{
	public:
		bool operator()(const Interval& a,const Interval& b)
		{
			return a.start<b.start;
		}
	};
	
	vector<Interval> merge(vector<Interval> &intervals){
		// Start typing your C/C++ solution below
		// DO NOT write int main() function   
		vector<Interval> result;
		if( 0 == intervals.size() )
			return result;
		sort( intervals.begin(), intervals.end(), cmp() );
		Interval itv = intervals[0];
		for( int i = 1; i < intervals.size(); ++i )
		{
			if( intervals[i].start > itv.end )
			{
				result.push_back( itv );
				itv = intervals[i];
				continue;
			}
			if( intervals[i].end > itv.end )
			{
				itv.end = intervals[i].end;
			}
		}
		result.push_back(itv);
		return result;	
    }
};

int main()
{
	Solution so;
	vector<Interval> vec;
	vec.push_back( Interval(17,19) );
	vec.push_back( Interval(1,3) );
	vec.push_back( Interval(2,6) );
	vec.push_back( Interval(8,10) );
	vec.push_back( Interval(15,18) );
	vector<Interval> result;
	result = so.merge( vec );
	for( int i = 0; i < result.size(); ++i )
	{
		cout << "[" << result[i].start << "," << result[i].end << "]";
	}
	return 0;
}
