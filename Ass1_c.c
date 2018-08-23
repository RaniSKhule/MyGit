/*
Insertion sort
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,a[50],n,temp;
	printf("\nEnter number of elements:- ");
	scanf("%d",&n);
	printf("\nEnter elements:- ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		if(a[i-1]>a[i])
		{
			temp=a[i];
			a[i]=a[i-1];
			a[i-1]=temp;
		}
	}
	printf("\nAfter sorting:- \n");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
	printf("\n");
	return 0;

}
