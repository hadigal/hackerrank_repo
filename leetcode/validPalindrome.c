bool isPalindrome(char* s)
{
    int len = strlen(s) - 1;
    int itr1 = 0;
    int itr2 = len;

    int flg = 0;

    while(itr1 <= len &&  itr2 >= 0)
    {
        if((s[itr1] <= 47) || ((s[itr1] >= 58) && (s[itr1] <= 64)) || ((s[itr1] >= 91) && (s[itr1] <= 96)) || (s[itr1] > 122))
        {
            ++itr1;
            continue;
        }

        if((s[itr2] <= 47) || ((s[itr2] >= 58) && (s[itr2] <= 64)) || ((s[itr2] >= 91) && (s[itr2] <= 96)) || (s[itr2] > 122))
        {
            --itr2;
            continue;
        }

        if((s[itr1] > 64 && s[itr1] < 91) && (s[itr2] > 96))
        {
            if(s[itr2] - s[itr1] == 32)
            {
                ++itr1;
                --itr2;
                continue;
            }
            else
            {
                return false;
            }
        }

        if((s[itr2] > 64 && s[itr2] < 91) && (s[itr1] > 96))
        {
            if(s[itr1] - s[itr2] == 32)
            {
                ++itr1;
                --itr2;
                continue;
                //return false;
            }
            else
            {
                return false;
            }
        }

        if(s[itr1] == s[itr2])
        {
            ++itr1;
            --itr2;
            continue;
        }
        else
        {
            return false;
        }

    }

    return true;
}
