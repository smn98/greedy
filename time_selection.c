#include<stdlib.h>
#include "quick_sort.h"

struct activity
{
	int profit;
	int deadline;
	int index;
}time[5],temp;

void bubblesort(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(time[j].profit < time[j+1].profit)
			{
				temp = time[j];
				time[j] = time[j+1];
				time[j+1] = temp;
			}
		}
	}
}

int maxima(int size)
{	
	int tempo=0;
	for(int i=0;i<size;i++)
	{
		if(time[i].deadline>tempo)
			tempo=time[i].deadline;
	}
	return (tempo);
}

void selection1(int n)
{	
	int size = maxima(n);
	int job[size];
	for(int i = 1; i <= size; i++)
	{
		job[i] = -1;
	}
	job[time[0].deadline] = time[0].index;
	//printf("%d %d %d \n ",size, job[time[0].deadline], time[0].deadline);
	
	for(int i = 1; i < n; i++)
	{
		while((time[i].deadline) >= 0)
		{
			if(job[time[i].deadline] == -1)
			{
				job[time[i].deadline] = time[i].index;
				break;
			}
			time[i].deadline--;
		}
	}
	for(int i = 1; i<= size; i++)
		printf("\n\n%d %d ",i , job[i]+1);
	printf("\n");
}

int main()
{
	for(int i = 0; i < 5; i++)
	{
		scanf("%d",&time[i].profit);
		scanf("%d",&time[i].deadline);
		time[i].index = i;
	}
	bubblesort(5);
	for(int i = 0; i < 5; i++)
	{
		printf("%d ",time[i].profit);
		printf("%d ",time[i].deadline);
		printf("%d \n",time[i].index+1);
	}
	selection1(5);
	
	return 0;
}
