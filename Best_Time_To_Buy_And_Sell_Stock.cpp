
int maxProfit(vector<int> &prices) 
{
	if( prices.size() < 2 ) return 0;
	int min = prices[0];
	int max_profit = prices[1] - prices[0];
	for( int i = 2; i < prices.size(); ++i )
	{
		if( prices[i-1] < min )
			min = prices[i-1];
		if( prices[i] - min > max_profit )
			max_profit = prices[i] - min;
	}
	if( max_profit < 0 ) 
		max_profit = 0;
	return max_profit;
}


