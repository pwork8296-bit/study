#include<stdio.h>

int bsearch(int a[],int n,int x)
{
	int l=0,u=n-1,mid;
	
	while(l<=u)
	{
		mid=(l+u)/2;
		if(x>a[mid])
		l=mid+1;
		else if(x<a[mid])
		u=mid-1;
		else
		return mid+1;
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
	p=bsearch(a,n,x);
	if(p==-1)
		printf("Element not found\n");
	else
		printf("Element found at position %d\n",p);
	return 0;
}
	
