class Solution {
public:
	void sortColors(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int color[3] = {0};
		for( int i = 0; i < n; ++i )
			color[A[i]]++;
		int index = 0;
		for( int i = 0; i < 3; ++i )
			for( int j = 0; j < color[i]; ++j )
				A[index++] = i;
	}
};

