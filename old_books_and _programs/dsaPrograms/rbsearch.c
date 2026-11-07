#include<stdio.h>

int rbsearch(int a[],int l,int u,int x)
{
	int mid;
	if(l>u)
	{
		return -1;
	}
	else if(l==u)
	{
		if(x==a[l])
			return l+1;
		else
			return -1;
	}
	else
	{
		mid=(l+u)/2;
		if(x>a[mid])
		return rbsearch(a,mid+1,u,x);
		else if(x<a[mid])
		return rbsearch(a,l,mid-1,x);
		else
		return mid+1;
	}
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
	p=rbsearch(a,0,n-1,x);
	if(p==-1)
		printf("Element not found\n");
	else
		printf("Element found at position %d\n",p);
	return 0;
}
	
