#include<stdio.h>
void quicksort(int a[],int l,int u)
{
	int i,j,temp,pivot;
	if(l<u)
	{
		i=l+1;
		j=u;
		pivot=a[l];
		while(i<=j)
		{
			while(a[i]<=pivot)
				i++;
			while(a[j]>pivot)
				j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[j];
		a[j]=a[l];
		a[l]=temp;
		quicksort(a,l,j-1);
		quicksort(a,j+1,u);
	}
}
int main()
{
	int a[100],n,i;
	printf("Enter array size\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("Sorted List is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
