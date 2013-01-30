class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int carry = 1;
		vector<int> result;
		for( int i = digits.size() - 1; i >= 0; --i )
		{
			digits[i] = digits[i] + carry;
			carry = digits[i] / 10;
			result.push_back( digits[i] % 10 );
		}
		if( carry > 0 )
			result.push_back( carry );
        reverse( result.begin(), result.end() );
		return result;
	}
};

