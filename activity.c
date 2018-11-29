#include<stdlib.h>
#include "quick_sort.h"

struct activity
{
	int start;
	int finish;
	int duration;
	int index;
}time[5],temp;

void bubblesort(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(time[j].finish > time[j+1].finish)
			{
				temp = time[j];
				time[j] = time[j+1];
				time[j+1] = temp;
			}
		}
	}
}

void selection(int n)
{	
	int temp=time[0].finish;
	printf("%d ",time[0].index+1);
	for(int i = 1; i < n; i++)
	{
		if(time[i].start>=temp)
		{
			printf("%d ",time[i].index+1);
			temp=time[i].finish;
		}	
	}

}
int main()
{
	for(int i = 0; i < 5; i++)
	{
		scanf("%d",&time[i].start);
		scanf("%d",&time[i].finish);
		time[i].duration = time[i].finish - time[i].start;
		time[i].index = i;
	}
	bubblesort(5);
	selection(5);
	
	return 0;
}
