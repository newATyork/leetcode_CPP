
//	Determine whether an integer is a palindrome. Do this without extra space.

//	Solution:
//	1.	Reverse the number, then compare the orginal number and reversed number by using % operation. But the reversion could overflow ( > INT_MAX ).
//	2.	no reversion. compare the left-most digit and the right-most digit. then modify this number.  n = (n % div)/10;
//	3.  Recursion.

#include <iostream>
using namespace std;

int Reverse( int n )
{
	int sum = 0;
	while( n != 0 )
	{
		int a = n % 10;
		sum = sum * 10 + a;
		n = n / 10;
	}
	return sum;
}

//	Solution 1:
bool isPalindromic_s1( int n )
{
	if( n < 0 ) return false;
	int rvs = Reverse( n );
	while( n != 0 )
	{
		int a = n % 10;
		int b = rvs % 10;
		if( a != b ) return false;
		n = n / 10;
		rvs = rvs / 10;
	}
	return true;
}

//	Solution 2:
bool isPalindromic_s2( int n )
{
	int div = 1;
	while( n / div >= 10 )
		div = div * 10;
	while( n != 0 )
	{
		int l = n / div;
		int r = n % 10;
		if( l != r ) return false;
		n = ( n % div ) / 10;
		div = div / 100;
	}
	return true;
}


bool isPalindromic_s3( int x, int& y );

//	Solution 3:
//	recursion method
bool isPalindromic_s3( int n )
{
	return isPalindromic_s3( n, n );
}

bool isPalindromic_s3( int x, int& y )
{
	if( x < 0 ) return false;
	if( x == 0 ) return true;
	if( isPalindromic_s3( x/10, y ) && ( x % 10 == y % 10 ) )
	{
		y = y / 10;
		return true;
	}
	else 
		return false;
}

int main()
{
	cout << isPalindromic_s2( 23454321 ) << endl;
	cout << isPalindromic_s2( 123454321 ) << endl;
	cout << isPalindromic_s2( 12321 ) << endl;
	return 0;
}
