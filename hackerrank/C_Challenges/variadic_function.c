#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000


int sum(int count,...)
{
  int i;
  int sum = 0;
  va_list arg_ptr;
  va_start(arg_ptr, count);
  for(i = 0; i < count; i++)
  {
    sum += va_arg(arg_ptr,int);
  }
  va_end(arg_ptr);
  return sum;
}

int min(int count,...)
{
  int i;
  va_list arg_ptr;
  va_start(arg_ptr, count);
  int *min_arr;
  min_arr = (int *)calloc(count,sizeof(int));
  if(!min_arr)
  {
    return EXIT_FAILURE;
  }
  for(i = 0; i < count; i++)
  {
    *(min_arr + i) = va_arg(arg_ptr,int);
  }
  int min = min_arr[0];
  for(i = 0; i < count; i++)
  {
    if(min_arr[i] < min)
    {
      min = min_arr[i];
    }
  }
  va_end(arg_ptr);
  free(min_arr);
  return min;
}

int max(int count,...)
{
  int i,max,*max_arr;
  max_arr = (int *)calloc(count,sizeof(int));
  if(!max_arr)
  {
    return EXIT_FAILURE;
  }
  va_list arg_ptr;
  va_start(arg_ptr,count);
  for(i = 0; i < count; i++)
  {
    max_arr[i] = va_arg(arg_ptr, int);
  }
  max = max_arr[0];
  for(i = 0; i < count; i++)
  {
    if(max_arr[i] > max)
    {
      max = max_arr[i];
    }
  }
  free(max_arr);
  va_end(arg_ptr);
  return max;
}

int test_implementations_by_sending_three_elements()
{
  srand(time(NULL));

  int elements[3];

  elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

  fprintf(stderr, "Sending following three elements:\n");
  for (int i = 0; i < 3; i++)
  {
    fprintf(stderr, "%d\n", elements[i]);
  }

  int elements_sum = sum(3, elements[0], elements[1], elements[2]);
  int minimum_element = min(3, elements[0], elements[1], elements[2]);
  int maximum_element = max(3, elements[0], elements[1], elements[2]);

  fprintf(stderr, "Your output is:\n");
  fprintf(stderr, "Elements sum is %d\n", elements_sum);
  fprintf(stderr, "Minimum element is %d\n", minimum_element);
  fprintf(stderr, "Maximum element is %d\n\n", maximum_element);

  int expected_elements_sum = 0;
  for (int i = 0; i < 3; i++)
  {
    if (elements[i] < minimum_element) {
        return 0;
    }

    if (elements[i] > maximum_element) {
        return 0;
    }

    expected_elements_sum += elements[i];
  }

  return elements_sum == expected_elements_sum;
}

int test_implementations_by_sending_five_elements()
{
  srand(time(NULL));

  int elements[5];

  elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

  fprintf(stderr, "Sending following five elements:\n");
  for (int i = 0; i < 5; i++)
  {
    fprintf(stderr, "%d\n", elements[i]);
  }

  int elements_sum = sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
  int minimum_element = min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
  int maximum_element = max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);

  fprintf(stderr, "Your output is:\n");
  fprintf(stderr, "Elements sum is %d\n", elements_sum);
  fprintf(stderr, "Minimum element is %d\n", minimum_element);
  fprintf(stderr, "Maximum element is %d\n\n", maximum_element);

  int expected_elements_sum = 0;
  for (int i = 0; i < 5; i++)
  {
    if (elements[i] < minimum_element)
    {
        return 0;
    }

    if (elements[i] > maximum_element)
    {
        return 0;
    }

    expected_elements_sum += elements[i];
  }

  return elements_sum == expected_elements_sum;
}

int test_implementations_by_sending_ten_elements()
{
  srand(time(NULL));

  int elements[10];

  elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[5] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[6] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[7] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[8] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
  elements[9] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

  fprintf(stderr, "Sending following ten elements:\n");
  for (int i = 0; i < 10; i++) {
      fprintf(stderr, "%d\n", elements[i]);
  }

  int elements_sum = sum(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                         elements[5], elements[6], elements[7], elements[8], elements[9]);
  int minimum_element = min(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                         elements[5], elements[6], elements[7], elements[8], elements[9]);
  int maximum_element = max(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                         elements[5], elements[6], elements[7], elements[8], elements[9]);

  fprintf(stderr, "Your output is:\n");
  fprintf(stderr, "Elements sum is %d\n", elements_sum);
  fprintf(stderr, "Minimum element is %d\n", minimum_element);
  fprintf(stderr, "Maximum element is %d\n\n", maximum_element);

  int expected_elements_sum = 0;
  for (int i = 0; i < 10; i++)
  {
    if (elements[i] < minimum_element)
    {
        return 0;
    }

    if (elements[i] > maximum_element)
    {
        return 0;
    }

    expected_elements_sum += elements[i];
  }

  return elements_sum == expected_elements_sum;
}

int main ()
{
  int number_of_test_cases;
  scanf("%d", &number_of_test_cases);

  while (number_of_test_cases--)
  {
    if (test_implementations_by_sending_three_elements())
    {
        printf("Correct Answer\n");
    }
    else
    {
        printf("Wrong Answer\n");
    }

    if (test_implementations_by_sending_five_elements())
    {
        printf("Correct Answer\n");
    } else {
        printf("Wrong Answer\n");
    }

    if (test_implementations_by_sending_ten_elements())
    {
        printf("Correct Answer\n");
    }
    else
    {
        printf("Wrong Answer\n");
    }
  }
  return 0;
}
