
//	3sum问题，
//	Solution:
//	O(n^2) time, 枚举每一个元素，转化成 O(n) 的 2sum 问题。

class Solution 
{
public:
	vector<vector<int> > threeSum(vector<int> &num) 
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<int> > output;
		if( num.size() < 3 ) 
			return output;
		sort( num.begin(), num.end() );
		int i = 0, j, k, n;
		n = num.size();
		while( i < n )
		{
			if( num[i] > 0 ) break;//no solution
			int temp = 0 - num[i];
			j = i + 1;
			k = n - 1;
			while( j < k )
			{
				int sum2 = num[j] + num[k];
				if( sum2 == temp )
				{
					//found one triplet
					vector<int> triplet;
					triplet.push_back(num[i]);
					triplet.push_back(num[j]);
					triplet.push_back(num[k]);
					output.push_back(triplet);
					//Be careful, we want to skip all the duplicate numbers, 
					//so that no duplicate triplets are recorded
					do j++;while( j < k && num[j-1] == num[j]);
					do k--;while( k > j && num[k+1] == num[k]);
				}
				else if( sum2 > temp )
					do k--;while( k > j && num[k+1] == num[k]);
				else if( sum2 < temp )
					do j++;while( j < k && num[j-1] == num[j]);
			}
			do i++;while( i < n && num[i-1] == num[i]);
		}
		return output;
	}
};
