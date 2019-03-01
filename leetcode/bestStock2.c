int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize == 0)
    {
        return 0;
    }
    int minVal = prices[0];
    int profit = 0;
    int ret = 0;

    for(size_t itr = 1; itr < pricesSize; ++itr)
    {
        profit = prices[itr] -  minVal;
        if(profit > 0)
        {
            minVal = prices[itr];
            ret += profit;
        }
        if(prices[itr] < minVal)
        {
            minVal = prices[itr];
        }

    }
    return ret;
}
