/*
Quick sort
*/

#include<stdio.h>
#include<stdlib.h>
void quick_Sort(int*,int,int);

int main()
{
	int arr[50],n,i;
	printf("\nEnter number of elements for sorting:- ");
	scanf("%d",&n);
	printf("\nEnter elements:- ");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	quick_Sort(arr,0,n-1);
	printf("\nAfter sorting:- \n");
	for(i=0;i<n;i++)
	printf("\t%d",arr[i]);
	printf("\n");	
	return 0;

}

void quick_Sort(int arr[50],int first,int last)
{
	int i,j,pivot,temp;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(arr[i]<=arr[pivot]&&i<last)
			i++;

			while(arr[j]>arr[pivot])
			j--;
		
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}

	temp=arr[pivot];
     	arr[pivot]=arr[j];
     	arr[j]=temp;
	quick_Sort(arr,first,j-1);
	quick_Sort(arr,j+1,last);
	}
	
	
}
