#include<stdio.h>

void merge(int a[],int l,int m,int u)
{
	int temp[100],lpos=l,mid=m-1,i,j=0;
	
	while(lpos<=mid&&m<=u)
	{
		if(a[lpos]<=a[m])
		{
			temp[j]=a[lpos];
			lpos++;
			j++;	
		}	
		else
		{
			temp[j]=a[m];
			m++;
			j++;
		}
	}	
	while(m<=u)
	{
		temp[j]=a[m];
		m++;
		j++;
	}
	while(lpos<=mid)
	{
		temp[j]=a[lpos];
		lpos++;
		j++;
	}
	
	for(i=l,j=0;i<=u;i++,j++)
	{
		a[i]=temp[j];
	}
}

void mergesort(int a[],int l,int u)
{
	int mid;
	if(l<u)
	{
		mid=(l+u)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,u);
		merge(a,l,mid+1,u);
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
	mergesort(a,0,n-1);
	printf("Sorted List is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
