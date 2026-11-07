#include<stdio.h>

int rlsearch(int a[],int n,int x)
{
	if(n==-1)
		return -1;
	else if(x==a[n])
		return n+1;
	else
		return rlsearch(a,n-1,x);
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
	p=rlsearch(a,n-1,x);
	if(p==-1)
		printf("Element not found\n");
	else
		printf("Element found at position %d\n",p);
	return 0;
}
	
