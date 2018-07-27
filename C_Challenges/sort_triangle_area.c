#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float area(int a, int b, int c)
{
  float p = ((float)a+(float)b+(float)c)/2.0;
  float area = sqrt((p * (p - (float)a) * (p - (float)b) * (p - (float)c)));

  return area;
}

void sort_by_area(triangle* tr, int n)
{
  // using selection sort technique
  triangle *temp = malloc(sizeof(triangle));
  int i,j,min;
  for(i = 0; i < n - 1; i++)
  {
    min = i;
    for(j = i+1; j < n; j++)
    {
      if(area(tr[min].a,tr[min].b,tr[min].c) > area(tr[j].a,tr[j].b,tr[j].c))
      {
        min = j;
      }
    }
    if(i != min)
    {
      temp->a = tr[i].a;
			temp->b = tr[i].b;
			temp->c = tr[i].c;

      tr[i].a = tr[min].a;
			tr[i].b = tr[min].b;
			tr[i].c = tr[min].c;

			tr[min].a = temp->a;
			tr[min].b = temp->b;
			tr[min].c = temp->c;
    }
  }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
