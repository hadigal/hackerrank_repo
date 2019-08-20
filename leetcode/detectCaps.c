/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.


Example 1:

Input: "USA"
Output: True


Example 2:

Input: "FlaG"
Output: False


Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

// easy Solution
bool detectCapitalUse(char * word)
{
    int itr = 1, cc = 0, len = strlen(word);
    bool flg = false;

    if(word[0] <= 90)
    {
        cc = 1;
        while(word[itr] != '\0')
        {
            if(word[itr] >= 65 && word[itr] <= 90)
            {
                ++cc;
            }
            ++itr;
        }

        if(cc == 1 || cc == len)
        {
            flg = true;
        }
    }
    else
    {
        flg = true;
        while(itr < len)
        {
            if(word[itr] < 97)
            {
                flg = false;
                break;
            }
            ++itr;
        }
    }

    return flg;
}
