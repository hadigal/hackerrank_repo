/************ DESC ***************
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101

Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.

Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.
**********************************/

bool hasAlternatingBits(int n)
{
    int num = n;
    bool flg = false;
    int temp1, temp2;
    int mask = 0x1;
    while(num != 0)
    {
        temp1 = num & mask;
        num >>= 1;

        if(num != 0)
        {
            temp2 = num & mask;
        }
        else
        {
            break;
        }

        if((temp1 ^ temp2) == 0)
        {
            flg = true;
            break;
        }
    }

    flg = flg?false:true;

    return flg;
}
