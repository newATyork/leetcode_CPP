class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        init();
        return fab(n);
    }
    int result[50];
    int init()
    {
        for( int i = 0; i < 50; ++i )
            result[i] = 0;
        result[0] = result[1] = 1;
    }
    int fab( int n )
    {
        if( result[n] != 0 ) return result[n];
        result[n] = fab( n - 1 ) + fab( n - 2 );
        return result[n];
    }
};
