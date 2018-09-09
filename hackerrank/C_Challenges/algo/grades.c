#include <stdio.h>
#include <stdlib.h>

typedef short unsigned int usint;

int main(void)
{
  usint num, *grades,*rGrades;
  scanf("%hu",&num);
  grades = (usint *)calloc(num,sizeof(usint));
  rGrades = (usint *)calloc(num,sizeof(usint));
  int temp = (3*num) + 1;

  for(int itr = 0; itr < num; itr++)
  {
    scanf("%hu",grades+itr);
    if(grades[itr] >= 38)
    {
      if(grades[itr] % 5 == 3 || grades[itr] % 5 == 8)
      {
        rGrades[itr] = grades[itr] + 2;
      }
      else if(grades[itr] % 5 == 4 || grades[itr] % 5 == 9)
      {
        rGrades[itr] = grades[itr] + 1;
      }
      else
      {
        rGrades[itr] = grades[itr];
      }
    }
    else
    {
      rGrades[itr] = grades[itr];
    }
  }

  for(int itr = 0; itr < num; itr++)
  {
    printf("%hu\n",rGrades[itr]);
  }
  free(grades);
  free(rGrades);
  return EXIT_SUCCESS;
}
