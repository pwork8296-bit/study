#include<stdio.h>
int main()
{
	int a[100],i,n,max;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("Enter array values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=1;i<10;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	printf("Maximum value is %d\n",max);
	return 0;
}
