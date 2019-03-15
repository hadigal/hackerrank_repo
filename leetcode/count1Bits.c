int hammingWeight(uint32_t n)
{
    uint32_t count = 0;
    size_t itr;
    uint32_t ret;

    for(itr = 0; itr < 32; ++itr)
    {
        ret = (n & 0x1);
        if(ret == 1)
        {
            ++count;
        }
        n = n >> 1;
    }
    return count;
}
