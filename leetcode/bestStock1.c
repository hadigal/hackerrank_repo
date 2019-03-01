int maxProfit(int* prices, int pricesSize)
{

    if(pricesSize == 0)
    {
        return 0;
    }

    int minVal = prices[0];
    int ret = 0;
    int profit = 0;

    for(size_t itr = 1; itr < pricesSize; ++itr)
    {
        profit = prices[itr] - minVal;
        // if(prices[itr] < minVal)
        // {
        //     minVal = prices[itr];
        // }

        minVal = prices[itr] < minVal?prices[itr]:minVal;
        // if(profit > ret)
        // {
        //     ret = profit;
        // }

        ret = profit>ret?profit:ret;
    }
    return ret;

}
