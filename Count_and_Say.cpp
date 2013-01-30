#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		string str = "1";
		for( int index = 2; index <= n ; ++index )
		{
			int cnt = 1;
			string tmp = "";
			for( int i = 1; i < str.length(); ++i )
			{
				if( str[i-1] != str[i] )
				{
					tmp += ( cnt + '0' );
					tmp += str[i-1];
					cnt = 1;
				}
				else
					cnt++;
			}
			tmp += ( cnt + '0' );
			tmp += str[str.length()-1];
			str = tmp;
		}
		return str;
	}
};

string count( int n )
{
	string str = "1";
	for( int index = 2; index <= n ; ++index )
	{
		int cnt = 1;
		string tmp = "";
		for( int i = 1; i < str.length(); ++i )
		{
			if( str[i-1] != str[i] )
			{
				tmp += ( cnt + '0' );
				tmp += str[i-1];
				cnt = 1;
			}
			else
				cnt++;
		}
		tmp += ( cnt + '0' );
		tmp += str[str.length()-1];
		str = tmp;
	}
	return str;
}

int main()
{
	string str;
	int n;
	while( cin >> n )
	{
		str = "";
		str = count( n );
		cout << str << "  !" << endl;
	}
	return 0;
}
