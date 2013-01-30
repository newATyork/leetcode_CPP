#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n1 = str2int(num1);
        int n2 = str2int(num2);
		return int2str(n1*n2);
    }
    int str2int( string num )
	{
		int sum = 0;
		for( int i = 0; i < num.size(); ++i )
			sum = sum * 10 + ( num[i] - '0' );
		return sum;
	}
	string int2str( int num )
	{
		if( num == 0 ) return "0";
		string result;
		int digit;
		while( num )
		{
			digit = num % 10;
			num = num / 10;
			result = char(digit + int('0')) + result;
		}
		return result;
	}
};


int main()
{
	Solution so;
	cout << so.multiply("0","0") << endl;
	return 0;
}
