#include<stdio.h>
int maximum(int a[],int n)
{
	int max=a[0],i;
	for(i=1;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	return max;
}
void ctingsort(int a[],int n,int max)
{
	int ct[max],i,j;
	for(i=0;i<max;i++)
	{
		ct[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		ct[a[i]]++;
	}
	
	for(i=0,j=0;i<max;i++)
	{
		while(ct[i]>0)
		{
			a[j++]=i;
			ct[i]--;
		}
	}
}
int main()
{
	int a[100],n,i,max;
	printf("Enter array size\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=maximum(a,n);
	ctingsort(a,n,max+1);
	printf("Sorted List is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
