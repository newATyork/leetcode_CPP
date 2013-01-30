class Solution {
public:
	int sqrt(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( x == 0 || x == 1 ) return x;
		double left = 0;
		double right = x;
		double epsilon = 0.01;
		while( true )
		{
			double mid = ( left + right ) / 2.0;
			double sqr = mid * mid;
			if( abs( sqr - x ) < epsilon )
				return mid;
			else if( sqr < x )
				left = mid;
			else if( sqr > x )
				right = mid;
		}
	}
};
