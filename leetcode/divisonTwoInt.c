int divide(int dividend, int divisor)
// {
//     if(dividend == 0)
//     {
//         return 0;
//     }

//     if(dividend == INT_MIN && divisor == -1)
//     {
//         return INT_MAX;
//     }
//     else if(dividend == INT_MIN && divisor == 1)
//     {
//         return INT_MIN;
//     }



//     int rem = dividend;
//     int64_t quot = 0;

//     if(dividend < 0)
//     {
//         while(rem < 0)
//         {
//             if(dividend < 0 && divisor < 0)
//             {
//                 ++quot;
//                 rem -= divisor;
//                 //printf("quot:%d rem:%d divisor:%d\n",quot,rem,divisor);
//             }
//             else if(dividend < 0 && divisor > 0)
//             {
//                 --quot;
//                 rem += divisor;
//                 //printf("quot:%d rem:%d divisor:%d\n",quot,rem,divisor);
//             }
//         }

//         if(rem > 0 && divisor > 0)
//         {
//             ++quot;
//         }
//         else if(rem > 0 && divisor < 0)
//         {
//             --quot;
//         }
//        //  printf("quot:%d rem:%d divisor:%d\n",quot,rem,divisor);
//        //  if(quot >= INT_MAX)
//        //  {
//        //      printf("int_max:%d quot:%d rem:%d divisor:%d\n",INT_MAX,quot,rem,divisor);
//        //      return INT_MAX;
//        //  }
//     }
//     else
//     {
//         while(rem > 0)
//         {
//             // ++quot;
//             // rem -= divisor;

//             if(dividend > 0 && divisor < 0)
//             {
//                 --quot;
//                 rem += divisor;
//                 // printf("quot:%d rem:%d divisor:%d\n",quot,rem,divisor);
//             }
//             else
//             {
//                 ++quot;
//                 rem -= divisor;
//             }
//         }
//         if(rem != 0 && divisor < 0)
//         {
//             quot++;
//         }
//         else if(rem != 0 && divisor > 0)
//         {
//             quot--;
//         }
//     }
//     return quot;
// }
{
    if(dividend == 0)
    {
        return 0;
    }

    if(dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    else if(dividend == INT_MIN && divisor == 1)
    {
        return INT_MIN;
    }


    int64_t quotient = 1;
    int remainder;
    int neg = 1;
    if ((dividend>0 &&divisor<0)||(dividend<0 && divisor>0))
        neg = -1;

    int64_t temp = dividend;
    int64_t tempDivisor = divisor;
    // Convert to positive
    uint64_t tempdividend = (dividend < 0) ? -temp : dividend;
    uint64_t tempdivisor = (divisor < 0) ? -tempDivisor : divisor;

    if (tempdivisor == tempdividend) {
        remainder = 0;
        return 1*neg;
    }
    else if (tempdividend < tempdivisor) {
        if (dividend < 0)
            remainder = tempdividend*neg;
        else
            remainder = tempdividend;
        return 0;
    }
    while (tempdivisor<<1 <= tempdividend)
    {
        tempdivisor = tempdivisor << 1;
        quotient = quotient << 1;
    }

    // Call division recursively
    if(dividend < 0)
        quotient = quotient*neg + divide(-(tempdividend-tempdivisor), divisor);
    else
        quotient = quotient*neg + divide(tempdividend-tempdivisor, divisor);

     if(quotient > INT_MAX)
     {
         quotient = INT_MAX;
     }
     else  if(quotient < INT_MIN)
     {
         quotient = INT_MIN;
     }
     return quotient;
 }
