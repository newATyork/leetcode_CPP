class Solution {
public:
	int reverse(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int flag = x >= 0 ? 1 : -1;
		x = x > 0 ? x : -x;
		int result = 0; 
		while( x != 0 )
		{
			result = result * 10 + x % 10;
			x = x / 10;
		}
		result = result * flag;
		return result;
	}
};

