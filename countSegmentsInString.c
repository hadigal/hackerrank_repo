/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

int countSegments(char * s)
{
    char *tk = strtok(s," ");
    int count  = 0;
    int flg = 0;

    while(tk != NULL)
    {
        if(flg != 1)
        {
            flg = 1;
        }

        if(*(tk+1) != ' ')
        {
            ++count;
        }

        tk = strtok(NULL," ");
    }

    return count;
}
