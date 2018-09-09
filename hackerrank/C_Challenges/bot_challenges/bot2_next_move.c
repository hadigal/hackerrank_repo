#include <stdio.h>
#include <string.h>
#include <math.h>

void col(int y,int c)
{
  if(c > y)
  {
    printf("LEFT\n");
  }
  else
  {
    printf("RIGHT\n");
  }
}

void row(int x, int r)
{
  if(r < x)
  {
    printf("DOWN\n");
  }
  else
  {
    printf("UP\n");
  }
}

void nextMove(int x, int y, int r, int c)
{
  //printf("x, y, r, c:%d,%d,%d,%d\n",x, y, r, c);
  if(x == r)
  {
    col(y,c);
  }
  else if(y == c)
  {
    row(x,r);
  }
  else if(r < x && c < y)
  {
    if((y - c) < (x - r))
    {
      printf("RIGHT\n");
    }
    else if((y - c) > (x - r) || (y - c) == (x - r))
    {
      printf("DOWN\n");
    }
  }
  else if(r > x && c > y)
  {
    if((c - y) < (r - x))
    {
      printf("LEFT\n");
    }
    else if((c - y) > (r - x) || (c - y) == (r - x))
    {
      printf("UP\n");
    }
  }
  else if(r > x && c < y)
  {
    if((y - c) < (r - x))
    {
      printf("RIGHT\n");
    }
    else if((y - c) > (r - x) || (y - c) == (r - x))
    {
      printf("UP\n");
    }
  }
  else if(r < x && c > y)
  {
    if((c - y) < (x - r))
    {
      printf("LEFT\n");
    }
    else if((c - y) > (x - r) || (c - y) == (x - r))
    {
      printf("DOWN\n");
    }
  }
}

int main(void)
{

  int x, y, r, c, m;

  scanf("%d", &m);
  scanf("%d", &r);
  scanf("%d", &c);

  char grid[101][101] = {};
  char line[101];
  setbuf(stdin,NULL);
  for(int i=0; i<m; i++)
  {
    scanf("%s", line);
    int len = strlen(line);
    for(int j = 0; j < len; j++)
    {
      if(line[j] == 'p' || line[j] == 'P')
      {
        x = i;
        y = j;
        break;
      }
    }
    strcpy(grid[i],line);
  }

  nextMove(x, y, r, c);
  return 0;
}
