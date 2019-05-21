int setBits(int num)
{
    int count = 0;

    while(num > 0)
    {
        if((num & 0x1) == 1)
        {
            ++count;
        }
        num >>= 1;
    }

    return count;
}

bool isPrime(int num)
{
    int itr;
    if(num == 1)
    {
        return false;
    }
    else if(num == 2)
    {
        return true;
    }

    for(itr = 2; itr <= (num/2); ++itr)
    {
        if((num%itr) == 0)
        {
            return false;
        }
    }
    return true;
}


int countPrimeSetBits(int L, int R)
{
    int itr = L;
    int setBitCount;
    int count = 0;

    while(itr <= R)
    {
        setBitCount = setBits(itr);
        if(isPrime(setBitCount) == true)
        {
            ++count;
        }

        ++itr;
    }

    return count;
}
