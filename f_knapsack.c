#include<stdlib.h>
#include "quick_sort.h"

struct knap
{
	float weight;
	float profit;
	float ratio;
	float fraction;
	int index;
}item[3],temp;

void bubblesort(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(item[j].ratio<item[j+1].ratio)
			{
				temp=item[j];
				item[j]=item[j+1];
				item[j+1]=temp;
			}
		}
	}
}
void f_knapsack(float m, int n)
{
	float u = m;
	int i = 0;
	while(u>0 && i<n)
	{
		if(item[i].weight > u)
		{
			item[i].fraction = u/item[i].weight;
			u = 0;
		}
		else
		{
			item[i].fraction = 1.0;
			u = u - item[i].weight;
		}
		i++;
	}
}
int main()
{
	for(int i = 0; i<3; i++)
	{
		scanf("%f",&item[i].weight);
		scanf("%f",&item[i].profit);
		item[i].ratio = item[i].profit/item[i].weight;
		item[i].fraction = 0.0;
		item[i].index = i;
	}
	bubblesort(3);
	f_knapsack( 20, 3);
	
	for(int i = 0; i<3; i++)
	{
		printf("%f ",item[i].weight);
		printf("%f ",item[i].fraction);
		printf("\n");
	}
	
	return 0;
}
