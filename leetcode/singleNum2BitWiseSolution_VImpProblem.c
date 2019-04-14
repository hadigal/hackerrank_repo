/* check this Explanation for solution
* https://www.geeksforgeeks.org/find-the-element-that-appears-once/
*/

int singleNumber(int* nums, int numsSize)
{
    int one = 0, two = 0; // init one and two to zero
    int commonBits;

    // iterate over all the elements
    for(int itr = 0; itr < numsSize; ++itr)
    {
        // common bits in one and two
        // store the bits common bits using bitwise & between previous "one" and
        // new arr element and add those bits to two
        two |= (one & nums[itr]);
        // now store bits repeating odd number of times between one and new array
        // element
        one ^= nums[itr];

        // clear the bits that repeat the 3rd time between one and two
        commonBits = ~(one & two);

        // remove the 3 time repeating bits from one and two
        one &= commonBits;
        two &= commonBits;
    }
    // the single value will be stored in 1
    return one;
}
