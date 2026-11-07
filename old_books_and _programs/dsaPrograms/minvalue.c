#include<stdio.h>
int main()
{
	int a[100],i,n,min;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("Enter array values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	min=a[0];
	for(i=1;i<10;i++)
	{
		if(min>a[i])
		min=a[i];
	}
	printf("Minimum value is %d\n",min);
	return 0;
}
