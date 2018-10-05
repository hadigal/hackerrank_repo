#include <stdio.h>
#include <stdlib.h>
// #define MAX 10

static int max_area_func(int area, int max_area)
{
  if(area > max_area)
  {
    return area;
  }
  else
  {
    return max_area;
  }
}

static int maxArea(int *height,int heightSize)
{
  int itr1 = 0;
  int itr2 = heightSize -1;
  int max_area = 0, max,len,h, area;
  while(itr1 <= itr2-1 || itr2 >= itr1+1)
  {
    if(height[itr1] >= height[itr2])
    {
      max = height[itr1];
      len = itr2 - itr1;
      h = height[itr2];
      area = len*h;
      max_area = max_area_func(area,max_area);
      --itr2;
    }
    else
    {
      max = height[itr2];
      len = itr2 -itr1;
      h = height[itr1];
      area = h*len;
      max_area = max_area_func(area,max_area);
      ++itr1;
    }
  }
  return max_area;
}

int main(void)
{
  int *height;
  int size;
  scanf("%d",&size);
  while((getchar()) != '\n');
  height = (int *)calloc(size,sizeof(height));
  for(int itr = 0; itr < size; ++itr)
  {
    scanf("%d",height+itr);
  }
  int area;
  area = maxArea(height,size);
  printf("%d\n",area);
  free(height);
  return EXIT_SUCCESS;
}
