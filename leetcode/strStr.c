int findIns(char *haystack, int itr1, char *ndl, int len)
{
    int itr = 0;
    int startVal = itr1;
    while(itr < len)
    {
        if(ndl[itr] != haystack[itr1])
        {
            return -1;
        }
        ++itr;
        ++itr1;
    }
    return startVal;
}

int strStr(char* haystack, char* needle)
{
    int itr1 = 0;
    int rc;
    int len1 = strlen(needle);
    int len2 = strlen(haystack);

    if(len1 > len2)
    {
        return -1;
    }

    if(needle == NULL || needle[itr1] == '\0')
    {
        return 0;
    }

    if(needle != NULL && haystack == NULL)
    {
        return -1;
    }

    if(len1 == len2)
    {
        rc = findIns(haystack,itr1,needle,len1);
        return rc;
    }

    while((len2 - itr1) >= len1)
    {
        rc = findIns(haystack,itr1,needle,len1);
        if(rc == -1)
        {
            ++itr1;
            continue;
        }
        else
        {
            printf("-->rc:%d\n",rc);
            return rc;
        }
    }
    return -1;
}
