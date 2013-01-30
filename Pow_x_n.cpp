class Solution {
public:
    double pow(double x, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		bool flag = false;
		if( n == 0 ) return 1;
		if( n < 0 ) 
		{
			flag = true;
			n = -n;
		}
        double power = x, result = 1.0;
        while (n > 0) {
            if ( 1 == n % 2 )
                result *= power;
            power *= power;
            n /= 2;
        }
		if( !flag )
			return result;
		return 1/result;
	}
};

