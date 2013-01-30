

//	找到一个数组中所有的递增 segment 。

int maxProfit(vector<int> &prices)
{
	if( prices.size() < 2 )
		return 0;
	int start = prices[0];
	int max_profit = 0;
	for( int i = 1; i < prices.size(); i++ )
	{
		if( prices[i] <= prices[i-1] )
		{
			max_profit += prices[i-1] - start;
			start = prices[i];
		}
	}
	max_profit += prices[ prices.size() - 1 ] - start;
	return max_profit;
}
