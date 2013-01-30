#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function     
		char roman[]="IVXLCDM";  
		string result = "";
		int index = 0;
		while( num > 0 )
		{
			int curdigit = num % 10;
			num = num / 10;
			string curstr = "";
			if( curdigit == 9 )
			{
				curstr += roman[index];
				curstr += roman[index+2];
			}
			else if( curdigit == 4 )
			{
				curstr += roman[index];
				curstr += roman[index+1];
			}
			else
			{
				if( curdigit >= 5 )
				{
					curstr += roman[index+1];
					curdigit -= 5;
				}
				for( int i = 0; i < curdigit; ++i )
					curstr += roman[index];
			}
			result = curstr + result;
			index += 2;
		}
		return result;
	}
};

int main()
{
	Solution so;
	int n = 888;
	cout << n << " " <<  so.intToRoman(n) << endl;
	return 0;
}
