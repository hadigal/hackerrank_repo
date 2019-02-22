int mySqrt(int x)
{
    if(x == 0 || x == 1)
    {
        return x;
    }

    unsigned int itr = 1;
    uint32_t val = 1;

    while(val <= x)
    {
        ++itr;
        val = itr*itr;
    }
    return (itr-1);
}
