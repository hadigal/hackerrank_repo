int countPrimes(int n)
{
    //bool *arr = (bool *)malloc(n*sizeof(*arr));
    if(n == 0)
    {
        return 0;
    }
    bool arr[n];
    memset(arr,false,n);
    int itr1,itr2;
    int count = 0;

    for(itr1 = 2; itr1 < n; ++itr1)
    {
        if(arr[itr1] == false)
        {
            ++count;
        }

        for(itr2 = 2; (itr1*itr2) < n; ++itr2)
        {
            arr[itr1*itr2] = true;
        }
    }

    //free(arr);
    return count;
}


// bool isPrime(int val)
// {
//     int mid = (val/2);

//     for(int itr = 2; itr <= mid; ++itr)
//     {
//         if((val%itr) == 0)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// int countPrimes(int n)
// {
//     int itr = 2;
//     int count = 0;
//     while(itr < n)
//     {
//         if(isPrime(itr) == true)
//         {
//             ++count;
//         }

//         ++itr;
//     }

//     return count;
// }
