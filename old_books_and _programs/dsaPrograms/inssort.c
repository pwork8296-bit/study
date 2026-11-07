#include<stdio.h>
void isort(int a[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		x=a[i];
		for(j=i-1;x<a[j]&&j>=0;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=x;
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
	isort(a,n);
	printf("Sorted List is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
