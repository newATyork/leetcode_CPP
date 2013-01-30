class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		sort( numbers.begin(), numbers.end() );
		vector<int> result;
		int left = 0;
		int right = numbers.size() - 1;
		while( left < right )
		{
			if( numbers[left] + numbers[right] < target )
				do left++; while( numbers[left] == numbers[left-1] );
			else if( numbers[left] + numbers[right] > target )
				do right--; while( numbers[right] == numbers[right+1] );
			else if( numbers[left] + numbers[right] == target )
			{
				result.push_back( left );
				result.push_back( right );
				break;
			}
		}
		return result;
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> result;
		for( int i = 0; i < numbers.size() - 1; ++i )
			for( int j = i + 1; j < numbers.size(); ++j )
			{
				if( numbers[i] + numbers[j] == target )
				{
					result.push_back(i);
					result.push_back(j);
					break;
				}
			}
		return result;
	}
};
