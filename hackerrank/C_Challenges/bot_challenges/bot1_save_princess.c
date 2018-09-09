#include <stdio.h>
#include <string.h>
#include <math.h>

void less(int m_cod,int p_cod, char * str)
{
  for(int i = m_cod; i < p_cod; i++)
  {
    printf("%s\n",str);
  }
}

void greater(int m_cod,int p_cod, char * str)
{
  for(int i = m_cod; i > p_cod; i--)
  {
    printf("%s\n",str);
  }
}

void displayPathtoPrincess(int m_x,int m_y,int x, int y)
{
  //printf("m_x,m_y,x,y:%d,%d,%d,%d\n",m_x,m_y,x,y);
  if(m_x < x)
  {
    less(m_x,x,"DOWN");
  }
  else if(m_x > x)
  {
    greater(m_x,x,"UP");
  }

  if(m_y < y)
  {
    less(m_y,y,"RIGHT");
  }
  else if(m_y > y)
  {
    greater(m_y,y,"LEFT");
  }
}

int main(void)
{
  int m;
  scanf("%d", &m);
  char grid[101][101]={};
  char line[101];

  int m_x,m_y,x,y;

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
      else if(line[j] == 'm' || line[j] == 'M')
      {
        m_x = i;
        m_y = j;
        break;
      }
    }
    strcpy(grid[i], line);
  }

  displayPathtoPrincess(m_x,m_y,x,y);
  return 0;
}
