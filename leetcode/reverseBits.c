uint32_t reverseBits(uint32_t n)
{
    uint32_t ret = 0;

    for(size_t itr = 0; itr < 32;++itr)
    {
        ret |= ((n&0x1)<<(31-itr));
        n = n >> 1;
    }
    return ret;
}
