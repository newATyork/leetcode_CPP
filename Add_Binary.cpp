
//	Add Binary number
//	a = "11", b = "1", result = "100"

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char AddBit( char a, char b, int& carry )
{
	if( a == '1' && b == '1' )
	{
		if( carry == 1 )
		{
			carry = 1;
			return '1';
		}
		else if( carry == 0 )
		{
			carry = 1;
			return '0';
		}
	}
	else if( (a == '1' && b == '0') || (a == '0' && b == '1') )
	{
		if( carry == 1 )
		{
			carry = 1;
			return '0';
		}
		else if( carry == 0 )
		{
			carry = 0;
			return '1';
		}
	}
	else if( a =='0' && b =='0' )
	{
		if( carry == 0 ) return '0';
		else if( carry == 1 )
		{
			carry = 0;
			return '1';
		}
	}
}

string Reverse( string str )
{
	int left = 0;
	int right = str.size() - 1;
	char tmp;
	while( left < right )
	{
		tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
	return str;
}

string AddBinary( string a, string b )
{
	string result = "";
	int la = a.size();
	int lb = b.size();
	if( la < lb )
	{
		string c = a;
		a = b;
		b = c;
	}
	int i = a.size() - 1;
	int j = b.size() - 1;

	int carry = 0;
	while( true )
	{
		result += AddBit( a[i], b[j], carry );
		i--;
		j--;
		if( j < 0 )
		{
			for( int k = i; k >= 0; k-- )
				result += AddBit( a[k], '0', carry );
			if( carry == 1 ) 
				result += '1';
			break;
		}
	}
	return Reverse( result );
}


int main()
{
	string a = "1";
	string b = "111";
	string result = AddBinary( a, b );
	cout << result << endl;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    char AddBit( char a, char b, int& carry )
    {
        if( a == '1' && b == '1' )
	    {
		    if( carry == 1 )
		    {
			    carry = 1;
			    return '1';
		    }
		    else if( carry == 0 )
		    {
			    carry = 1;
			    return '0';
		    }
	    }
	    else if( (a == '1' && b == '0') || (a == '0' && b == '1') )
	    {
		    if( carry == 1 )
		    {
			    carry = 1;
			    return '0';
		    }
		    else if( carry == 0 )
		    {
			    carry = 0;
			    return '1';
		    }
	    }
	    else if( a =='0' && b =='0' )
	    {
		    if( carry == 0 ) return '0';
		    else if( carry == 1 )
		    {
			    carry = 0;
			    return '1';
		    }
	    }
    }

    string Reverse( string str )
    {
	    int left = 0;
	    int right = str.size() - 1;
	    char tmp;
	    while( left < right )
	    {
		    tmp = str[left];
		    str[left] = str[right];
		    str[right] = tmp;
		    left++;
		    right--;
	    }
	    return str;
    }

    string addBinary( string a, string b )
    {
	    string result = "";
	    int la = a.size();
	    int lb = b.size();
	    if( la < lb )
	    {
		    string c = a;
		    a = b;
		    b = c;
	    }
	    int i = a.size() - 1;
	    int j = b.size() - 1;

	    int carry = 0;
	    while( true )
	    {
		    result += AddBit( a[i], b[j], carry );
		    i--;
		    j--;
		    if( j < 0 )
		    {
                char zero = '0';
    			for( int k = i; k >= 0; k-- )
				    result += AddBit( a[k], zero, carry );
			    if( carry == 1 ) 
				    result += '1';
			    break;
		    }
	    }
	    return Reverse( result );
    }
};
