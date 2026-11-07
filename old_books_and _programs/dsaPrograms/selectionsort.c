#include<stdio.h>
void selsort(int a[],int n)
{
	int i,min_pos,j,temp;
	for(i=0;i<n-1;i++)
	{
		min_pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min_pos]>a[j])
			min_pos=j;
		}
		if(min_pos!=i)
		{
			temp=a[i];
			a[i]=a[min_pos];
			a[min_pos]=temp;
		}
	}
}

int main()
{
	int a[100],n,i;
	printf("Enter arrya size\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selsort(a,n);
	printf("Sorted List is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
