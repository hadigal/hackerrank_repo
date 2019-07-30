/*
Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.

If there aren't two consecutive 1's, return 0.



Example 1:

Input: 22
Output: 2
Explanation:
22 in binary is 0b10110.
In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, which is 2.
Example 2:

Input: 5
Output: 2
Explanation:
5 in binary is 0b101.
Example 3:

Input: 6
Output: 1
Explanation:
6 in binary is 0b110.
Example 4:

Input: 8
Output: 0
Explanation:
8 in binary is 0b1000.
There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.


Note:

1 <= N <= 10^9
*/

// logic is simple store the curr count of consecutive one's(ie distance between
// two 1's in a bin num). if curr count is > max store in max. Also use a prev
// var to store the value of prev value at the given bit; initialize this with -1
// start.

int binaryGap(int N)
{
    int prev = -1, curr = 0, max = 0, val = N;

    while(val > 0)
    {
        if((val & 0x1) == 1)
        {
            if(prev == -1)
            {
                curr = 0;
            }
            else if(prev == 1)
            {
                curr = 1;
            }
            else
            {
                ++curr;
            }

            prev = 1;
            max = (curr > max)?curr:max;
            curr = 0;
        }
        else
        {
            if(prev != -1)
            {
                ++curr;
                prev = 0;
            }
        }

        val >>= 1;
    }

    return max;
}
