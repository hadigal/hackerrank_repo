/*
Given a string array words, find the maximum value of
length(word[i]) * length(word[j]) where the two words do not share common letters.
You may assume that each word will contain only lower case letters.
If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
*/


int maxProduct(char ** words, int len)
{
    int *maskArr = (int *)malloc(len*sizeof(*maskArr));
    int *lenArr = (int *)malloc(len*sizeof(*lenArr));
    int tmp;
    for(int itr = 0; itr < len; ++itr)
    {
        tmp = 0;
        lenArr[itr] = strlen(words[itr]);
        for(int itr2 = 0; itr2 < lenArr[itr];++itr2)
        {
            tmp |= (1 << (words[itr][itr2] - 'a'));
        }
        maskArr[itr] = tmp;
    }

    tmp = 0;
    int max = 0;

    for(int itr1 = 0; itr1 < len; ++itr1)
    {
        for(int itr2 = itr1+1; itr2 < len; ++itr2)
        {
            if((maskArr[itr1] & maskArr[itr2]) == 0)
            {
                tmp = lenArr[itr1]*lenArr[itr2];

                max = (tmp > max)?tmp:max;
            }
        }
    }

    free(maskArr);
    free(lenArr);
    return max;
}
