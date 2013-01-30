
//题目：给定一个数组arr和一个数字target，找到3个数字 a,b,c 且 a + b + c 与 target 的差最小

//思路：与 3sum 类似。排序，枚举每个元素，两个指针往中间扫。并且不断更新最小差值。

#include <iostream>
using namespace std;

void swap( int& a, int& b )
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Quicksort( int* arr, int low, int high )
{
	if( low >= high )
		return;
	int t = arr[low];
	int left = low;
	int right = high + 1;
	while( true )
	{
		do left++; while( left < right && arr[left] < t );
		do right--;while( left < right && arr[right] > t );
		if( left > right ) break;
		swap( arr[left], arr[right] );
	}
	swap( arr[low], arr[right] );
	Quicksort( arr, low, right - 1 );
	Quicksort( arr, right + 1, high );
}

void Find3sumclose( int* arr, int len, int target)
{
	int min_diff = 0x7FFFFFFF;
	int a, b, c;
	Quicksort( arr, 0, len - 1 );
	
	for( int i = 0 ; i < len ; ++i )
		cout << arr[i] << " ";
	
	cout << endl;
	int i, j, k;
	int diff;
	i = 0;
	while( i < len )
	{
		int sum2 = target - arr[i];
		j = i + 1;
		k = len - 1;
		while( j < k )
		{
			int tmp = arr[j] + arr[k];
			if( tmp < sum2 )
			{
				diff = sum2 - tmp;
				if( diff < min_diff ) 
				{
					min_diff = diff;
					a = arr[i]; b = arr[j]; c = arr[k];
				}
				j++;
			}
			else if( tmp > sum2 )
			{
				diff = tmp - sum2;
				if( diff < min_diff )
				{
					min_diff = diff;
					a = arr[i]; b = arr[j]; c = arr[k];
				}
				k--;
			}
			else if( tmp == sum2 )
			{
				min_diff = 0;
				a = arr[i]; b = arr[j]; c = arr[k];
				break;
			}
		}
		i++;
	}
	cout << a << " " << b << " " << c << endl;
	cout <<"target : "<<target << endl;
	cout <<"sum : "<< a + b + c << endl;
	cout <<"min_diff : "<< min_diff << endl;
}


int main()
{
	int arr[] = { 87,6,-100,-19,10,-8,-58,56,14,-1,-42,-45,-17,10,20,-4,13,-17,0,11,-44,65,74,-48,30,-91,13,-53,76,-69,-19,-69,16,78,-56,27,41,67,-79,-2,30,-13,-60,39,95,64,-12,45,-52,45,-44,73,97,100,-19,-16,-26,58,-61,53,70,1,-83,11,-35,-7,61,30,17,98,29,52,75,-73,-73,-23,-75,91,3,-57,91,50,42,74,-7,62,17,-91,55,94,-21,-36,73,19,-61,-82,73,1,-10,-40,11,54,-81,20,40,-29,96,89,57,10,-16,-34,-56,69,76,49,76,82,80,58,-47,12,17,77,-75,-24,11,-45,60,65,55,-89,49,-19,4 };
	Find3sumclose( arr, sizeof(arr)/sizeof(arr[0]), -275 );
	return 0;
}
