#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

int *tmp;

long count = 0;

void cpy(int *arr, int *tmp, int lIdx, int rIdx)
{
    for(int itr = lIdx; itr <= rIdx; ++itr)
    {
        arr[itr] = tmp[itr];
    }
}

void merge(int *arr, int *tmp, int lIdx1, int rIdx1, int lIdx2, int rIdx2)
{
    int itr1 = lIdx1;
    int itr2 = lIdx2;
    int itr3 = lIdx1;

    long int val;

    while(itr1 <=rIdx1 && itr2 <= rIdx2)
    {
        if(arr[itr2] < arr[itr1])
        {
            //printf("itr1:%d\nitr2:%d\n",itr1,itr2);
            val = itr3 - itr2;
            //printf("val:%ld\n", val);
            count += val;
            tmp[itr3++] = arr[itr2++];
        }
        else
        {
            tmp[itr3++] = arr[itr1++];
        }
    }

    while(itr1 <= rIdx1)
    {
        tmp[itr3++] = arr[itr1++];
    }

    while(itr2 <= rIdx2)
    {
        tmp[itr3++] = arr[itr2++];
    }

    return;
}

// Complete the countInversions function below.
void countInversions(int* arr, int lIdx, int rIdx)
{
    int mid;

    if(lIdx < rIdx)
    {
        mid = (lIdx+rIdx)/2;
        countInversions(arr,lIdx,mid);
        countInversions(arr,mid+1,rIdx);
        merge(arr,tmp,lIdx,mid,mid+1,rIdx);
        cpy(arr,tmp,lIdx,rIdx);
    }
    return;
}

void display(int *arr, int len)
{
    for(int itr = 0; itr < len; ++itr)
    {
        printf("arr[%d]:%d\n",itr,arr[itr]);
    }
}

int main()
{

//     int lines;
//     scanf("%d",&lines);
//     printf("lines:%d\n",lines);
//     long int *res = (long int *)calloc(lines,sizeof(*res));

//     for(int itr = 0; itr < lines; ++itr)
//     {
//         int temp;
//         int *arr;
//         scanf("%d",&temp);
//         arr = (int *)calloc(temp,sizeof(*arr));
//         for(int itr1 = 0; itr1 < temp; ++itr1)
//         {
//             scanf("%d",arr+itr);
//         }
//         display(arr,temp);
//         countInversions(arr,0,temp-1);
//         display(arr, temp);
//         printf("count:%ld\n",count);
//         res[itr] = count;
//         count = 0;
//         free(arr);
//     }

//     for(int itr2 = 0; itr2 < lines; ++itr2)
//     {
//         printf("%ld\n",res[itr2]);
//     }
//     return EXIT_SUCCESS;
// }
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char** arr_temp = split_string(readline());

        int* arr = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            char* arr_item_endptr;
            char* arr_item_str = *(arr_temp + i);
            int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

            if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(arr + i) = arr_item;
        }

        int arr_count = n;
        tmp = (int *)calloc(arr_count, sizeof(*tmp));
        //printf("\n------ before ------\n");
        //display(arr, arr_count);
        countInversions(arr, 0, arr_count-1);
        //printf("\n------ After ------\n");
        //printf("%ld\n",count*(-1));
        //display(arr,arr_count);
        //printf("\n-----------itr:%d----------\n",t_itr);
        //display(tmp,arr_count);
        free(tmp);
        fprintf(fptr, "%ld\n", count*(-1));
        free(arr);
        count = 0;
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
