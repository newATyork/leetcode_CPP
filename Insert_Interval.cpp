#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<Interval> result;
		// occurrence
		bool flag = false;
		for( int i = 0; i < intervals.size(); ++i )
		{
			// no overlapping with newInterval
			if( intervals[i].end < newInterval.start )
			{
				result.push_back( intervals[i] );
				continue;
			}
			// newInterval is on the unused space
			if( intervals[i].start > newInterval.end )
			{
				if( flag == false ) 
				{
					result.push_back( newInterval );
					flag = true;
					result.push_back( intervals[i] );
				}
				else if( flag == true )
				{
					result.push_back( intervals[i] );
				}
				continue;
			}
			// newInterval is overlapping with a current interval	
			if( intervals[i].start < newInterval.start )
			{
				newInterval.start = intervals[i].start;
			}
			if( intervals[i].end > newInterval.end )
			{
				newInterval.end = intervals[i].end;
				result.push_back( newInterval );
				flag = true;
			}
		}
		if( flag == false )
			result.push_back( newInterval );
		return result;
	}
};

int main()
{
	Solution so;

	return 0;
}
