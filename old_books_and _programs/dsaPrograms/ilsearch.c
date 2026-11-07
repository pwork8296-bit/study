#include<stdio.h>

int lsearch(int a[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(x==a[i])
			return i+1;
	}
	return -1;
}

int main()
{
	int a[100],i,n,x,p;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("Enter array values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to search\n");
	scanf("%d",&x);
	p=lsearch(a,n,x);
	if(p==-1)
		printf("Element not found\n");
	else
		printf("Element found at position %d\n",p);
	return 0;
}
	
