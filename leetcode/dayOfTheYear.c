/*
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD,
return the day number of the year.

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61

Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
*/

// efficient solution split the string at "-" token, at first check if year is a
// leap year, if yes then set leap year flg. Now move to month if month
// is > 2 && leap_year_flg == true then add +1 to days at start of current month,
// else just store the val at month idx from static arr in days variable.
// now finally add the current date value to days variable and return the days.
int dayOfYear(char * date)
{
    int mnt[12] = {0,31,59,90,120,151,181,212,243,273,304,334};

    char *tk = strtok(date,"-");
    int val, c= 0, days = 0;
    bool lflg = false;

    while(tk != NULL)
    {
        //val = sscanf(tk,"%u",&val);
        val = (int)strtol(tk,(char **)(NULL),10);
        if(c == 0)
        {
            int tmp = val;
            if(tmp%100 == 0)
            {
                if(tmp%400 == 0)
                {
                    lflg = true;
                }
            }
            else
            {
                if(tmp%4 == 0)
                {
                    lflg = true;
                }
            }
        }
        else if(c == 1)
        {
            days = mnt[val-1];
            if(lflg == true)
            {
                days = (val > 2)?(days+1):days;
            }
        }
        else
        {
            days += val;
        }
        tk = strtok(NULL,"-");
        ++c;
    }

    return days;
}
