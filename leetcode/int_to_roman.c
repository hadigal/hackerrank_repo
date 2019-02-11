#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHUN "CM"
#define FRHN "CD"
#define NINT "XC"
#define FORT "XL"
#define NINE "IX"
#define FOUR "IV"
#define HUND "C"
#define FHUN "D"
#define FIFT "L"
#define ONE "I"
#define TWO "II"
#define THRE "III"
#define FIVE "V"
#define SIX "VI"
#define SEVN "VII"
#define EIGT "VIII"
#define TEN "X"

typedef struct
{
    char *c;
    int x;
}Data;

Data d;
char *ret;

Data thousand(int num)
{
    int new_num = (num%1000);
    int temp = num - new_num;

    if(temp == 1000)
    {
       snprintf(d.c,2,"%s","M");
       //printf("d.c:%s\n",d.c);
       d.x = new_num;
    }
    else if(temp == 2000)
    {
       snprintf(d.c,3,"%s","MM");
       d.x = new_num;
    }
    else
    {
       d.c = (char *)realloc(d.c,4*sizeof(*d.c));
       snprintf(d.c,4,"%s","MMM");
       d.x = new_num;
    }

    return d;
}

Data hundred(int num)
{
    int new_num = (num%100);
    int temp = num - new_num;

    if(temp == 100)
    {
       int temp_len = strlen(HUND)+1;
       //int len = 3+temp_len;
       //d.c = (char *)realloc(d.c,len*sizeof(*d.c));
       snprintf(d.c,temp_len,"%s",HUND);
       d.x = new_num;
       return d;
    }
    else if(temp == 500)
    {
       snprintf(d.c,strlen(FHUN)+1,"%s",FHUN);
       d.x = new_num;
       return d;
    }
    else if(temp == 400)
    {
        snprintf(d.c,strlen(FRHN)+1,"%s",FRHN);
        d.x = new_num;
        return d;
    }
    else if(temp == 900)
    {
        snprintf(d.c,strlen(NHUN)+1,"%s",NHUN);
        //printf("d.c:%s\n",d.c);
        d.x = new_num;
        return d;
    }
    else
    {
       if((temp > 100) && (temp < 400))
       {
           if(temp == 200)
           {
               int temp_len = 2*strlen(HUND) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s",HUND,HUND);
               d.x = new_num;
               return d;
           }
           else
           {
               int temp_len = 3*strlen(THRE) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s%s",HUND,HUND,HUND);
               d.x = new_num;
               return d;
           }
       }
       else
       {
           if(temp == 600)
           {
               int temp_len = 2*strlen(FHUN) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s",FHUN,HUND);
               d.x = new_num;
               return d;
           }
           else if(temp == 700)
           {
               int temp_len = 3*strlen(FHUN)+1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s%s",FHUN,HUND,HUND);
               d.x = new_num;
               return d;
           }
           else
           {
               int temp_len = 4*strlen(FHUN) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s%s%s",FHUN,HUND,HUND,HUND);
               d.x = new_num;
               return d;
           }
       }
    }
    //return d;
}

Data tens(int num)
{
    int new_num = (num%10);
    int temp = num - new_num;

    if(temp == 10)
    {
       snprintf(d.c,strlen(TEN)+1,"%s",TEN);
       d.x = new_num;
       return d;
    }
    else if(temp == 50)
    {
       snprintf(d.c,strlen(FIFT)+1,"%s",FIFT);
       d.x = new_num;
       return d;
    }
    else if(temp == 40)
    {
        snprintf(d.c,strlen(FORT)+1,"%s",FORT);
        d.x = new_num;
        return d;
    }
    else if(temp == 90)
    {
        snprintf(d.c,strlen(NINT)+1,"%s",NINT);
        //printf("d.c:%s\n",d.c);
        d.x = new_num;
        return d;
    }
    else
    {
       if((temp > 10) && (temp < 40))
       {
           if(temp == 20)
           {
               int temp_len = 2*strlen(TEN) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s",TEN,TEN);
               d.x = new_num;
               return d;
           }
           else
           {
               int temp_len = 3*strlen(TEN) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s%s",TEN,TEN,TEN);
               d.x = new_num;
               return d;
           }
       }
       else
       {
           if(temp == 60)
           {
               int temp_len = 2*strlen(FIFT) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s",FIFT,TEN);
               d.x = new_num;
               return d;
           }
           else if(temp == 70)
           {
               int temp_len = 3*strlen(FIFT) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s%s",FIFT,TEN,TEN);
               d.x = new_num;
               return d;
           }
           else
           {
               int temp_len = 4*strlen(FIFT) + 1;
               d.c = (char *)realloc(d.c,temp_len*sizeof(*d.c));
               snprintf(d.c,temp_len,"%s%s%s%s",FIFT,TEN,TEN,TEN);
               d.x = new_num;
               return d;
           }
       }
    }
    //return d;
}
char* intToRoman(int num)
{
    d.c = (char *)calloc(3,sizeof(*d.c));
    ret = (char *)calloc(16,sizeof(*ret));
    int counter = 0;
    Data temp_data;
    if(num >= 1000)
    {
        temp_data = thousand(num);
        //printf("num:%d...\n",num);
        if(num == 1000)
        {
            free(ret);
            return temp_data.c;
        }
        else
        {
            num = temp_data.x;
            //printf("temp_data.c:%s...\n",temp_data.c);
            int temp_len = strlen(temp_data.c);
            snprintf(ret,temp_len+1,"%s",temp_data.c);
            //printf("ret:%s\n",ret);
            //printf("counter:>>>>>:%d\n",counter);
            counter += temp_len;
        }
    }
    if(num >= 100)
    {
        temp_data = hundred(num);
        if(num == 100)
        {
            //free(ret);
            //printf("^^^^num:%d...\n",num);

            int temp_len = strlen(temp_data.c);
            snprintf(ret+counter,temp_len+1,"%s",temp_data.c);
            counter += temp_len;
            return ret;
        }
        else
        {
            num = temp_data.x;
            //printf("^^^^num:%d...\n",num);
            int temp_len = strlen(temp_data.c);
            snprintf(ret+counter,temp_len+1,"%s",temp_data.c);
            //printf("ret:%s\n",ret);
            //printf("counter:>>>>>:%d\n",counter);
            counter += temp_len;
        }
    }
    if(num >= 10)
    {
        temp_data = tens(num);
        ////printf("^^^^num:%d...\n",num);
        if(num == 10)
        {
            int temp_len = strlen(temp_data.c);
            snprintf(ret+counter,temp_len+1,"%s",temp_data.c);
            counter += temp_len -1;
            return ret;
        }
        else
        {
            num = temp_data.x;
            //printf("^^^^num:%d...\n",num);
            int temp_len = strlen(temp_data.c);
            snprintf(ret+counter,temp_len+1,"%s",temp_data.c);
            //printf("ret:%s\n",ret);
            //printf("counter:>>>>>:%d\n",counter);
            counter += temp_len;
        }
    }
    if(num < 10)
    {
        //printf("-------->num:%d...\n",num);
        if(num == 1)
        {
            int temp_len = strlen(ONE);
            snprintf(ret+counter,temp_len+1,"%s",ONE);
            counter += temp_len;
            //return ret;
        }
        else if(num == 2)
        {
            int temp_len = strlen(TWO);
            snprintf(ret+counter,temp_len+1,"%s",TWO);
            counter += temp_len;
            //return ret;
        }
        else if(num == 3)
        {
            int temp_len = strlen(THRE);
            snprintf(ret+counter,temp_len+1,"%s",THRE);
            counter += temp_len;
            //return ret;
        }
        else if(num == 4)
        {
            //printf("-------->num:%d...\n",num);
            int temp_len = strlen(FOUR);
            snprintf(ret+counter,temp_len+1,"%s",FOUR);
            //printf("ret:%s\n",ret);
            //printf("counter:>>>>>:%d\n",counter);
            counter += temp_len;
            //return ret;
        }
        else if(num == 5)
        {
            int temp_len = strlen(FIVE);
            snprintf(ret+counter,temp_len+1,"%s",FIVE);
            counter += temp_len;
            //return ret;
        }
        else if(num == 6)
        {
            int temp_len = strlen(SIX);
            snprintf(ret+counter,temp_len+1,"%s",SIX);
            counter += temp_len;
            //return ret;
        }
        else if(num == 7)
        {
            int temp_len = strlen(SEVN);
            snprintf(ret+counter,temp_len+1,"%s",SEVN);
            counter += temp_len;
            //return ret;
        }
        else if(num == 8)
        {
            int temp_len = strlen(EIGT);
            snprintf(ret+counter,temp_len+1,"%s",EIGT);
            counter += temp_len;
            //return ret;
        }
        else if(num == 9)
        {
            int temp_len = strlen(NINE);
            snprintf(ret+counter,temp_len+1,"%s",NINE);
            //printf("d.c:%s\n",d.c);
            counter += temp_len;
            //return ret;
        }
    }
    free(d.c);
    return ret;
}

int main(void)
{
  int num;
  scanf("%d",&num);
  char *ret_val = intToRoman(num);
  printf("%s\n",ret_val);
  free(ret_val);
  return EXIT_SUCCESS;
}
