

char * reverseWords(char * s)
{
    if(s == NULL)
    {
        return s;
    }

    char **store = (char **)malloc(1*sizeof(*store));
    int c = 0;
    int wc = 0;

    int len = strlen(s);
    int start = -1;
    int end = -1;

    while(c < len)
    {
        if(s[c] != ' ')
        {
            if(start == -1)
            {
                start = c;
                end = c;
            }
            else
            {
                end = c;
            }
            ++c;
            continue;
        }
        else
        {
            if(start != -1 && end != -1)
            {
                int tmpLen = end - start;
                if(wc > 0)
                {
                    store = (char **)realloc(store,sizeof(*store)*(wc+1));
                }

                store[wc] = (char *)malloc((tmpLen+2)*sizeof(char));
                snprintf(store[wc],tmpLen+2,"%s",s+start);
                wc++;
                start = -1;
                end = -1;
            }
        }
        ++c;

    }

    if(start != -1 && end != -1)
    {
        int tmpLen = end - start;
        if(wc > 0)
        {
            store = (char **)realloc(store,sizeof(*store)*(wc+1));
        }

        store[wc] = (char *)malloc((tmpLen+2)*sizeof(char));
        snprintf(store[wc],tmpLen+2,"%s",s+start);
        wc++;
    }

   if(wc >= 1)
   {
        c = wc-1;
        int sItr = 0;
        while(c >= 0 && sItr < len)
        {
            int itr = 0;
            while(store[c][itr] != '\0')
            {
                s[sItr++] = store[c][itr++];
            }
            s[sItr++] = ' ';

            free(store[c]);
            --c;
        }
        s[sItr-1] = '\0';
   }
   else
   {
       s[0] = '\0';
   }

    free(store);
    return s;
}
