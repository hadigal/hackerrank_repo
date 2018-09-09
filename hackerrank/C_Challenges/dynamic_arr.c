#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
  int total_number_of_shelves;
  scanf("%d", &total_number_of_shelves);

  int flag = 1;
  total_number_of_books = (int *)calloc(total_number_of_shelves,sizeof(int));
  if(!total_number_of_books)
  {
    printf("Error:calloc(total_books)\n");
    exit(EXIT_FAILURE);
  }

  int total_number_of_queries;
  scanf("%d", &total_number_of_queries);
  total_number_of_pages = (int **)calloc(total_number_of_shelves,sizeof(int *));
  if(!total_number_of_pages)
  {
    printf("error:calloc(total_pages)\n");
    exit(EXIT_FAILURE);
  }
  for(int i = 0; i < total_number_of_shelves;i++)
  {
    *(total_number_of_pages + i) = (int *)calloc(1,sizeof(int));
    if(!(*total_number_of_pages + i))
    {
      printf("error:calloc(*total_pages + i)\n");
      exit(EXIT_FAILURE);
    }
  }

  while (total_number_of_queries--)
  {
    int type_of_query;
    scanf("%d", &type_of_query);

    //query error check
    if(type_of_query  > 3 || type_of_query < 1)
    {
      printf("ERROR:Query # incorrect\n");
      exit(EXIT_FAILURE);
    }

    if (type_of_query == 1)
    {
      /*
      * Process the query of first type here.
      */
      int shelf, pages;
      scanf("%d %d", &shelf, &pages);

      // incrementing the number of books in user i/p shelf.
      total_number_of_books[shelf] += 1;
      // based on the input for book allocating new space in the array for books
      // page # based on the index value.
      *(total_number_of_pages + shelf) = realloc(*(total_number_of_pages + shelf), total_number_of_books[shelf]*sizeof(int));
      // error check for realloc
      if(!(*total_number_of_pages + shelf))
      {
        printf("Error:realloc(*total_number_of_pages + shelf)\n");
        exit(EXIT_FAILURE);
      }

      *(*(total_number_of_pages + shelf)+(total_number_of_books[shelf]-1)) = pages;
    }
    else if (type_of_query == 2)
    {
      int x, y;
      scanf("%d %d", &x, &y);
      printf("%d\n", *(*(total_number_of_pages + x) + y));
    }
    else
    {
      int x;
      scanf("%d", &x);
      printf("%d\n", *(total_number_of_books + x));
    }
  }
  if (total_number_of_books)
  {
    free(total_number_of_books);
  }

  for (int i = 0; i < total_number_of_shelves; i++)
  {
    if (*(total_number_of_pages + i))
    {
      free(*(total_number_of_pages + i));
    }
  }

  if (total_number_of_pages)
  {
    free(total_number_of_pages);
  }
  return 0;
}
