/*
Selection sort
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
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\nAfter sorting:- \n");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
	printf("\n");
	return 0;

}
