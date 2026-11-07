#include<stdio.h>
void bubsort(int a[],int n)
{
	int i,flag,j,temp,l=n-1;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<l;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		return;
		else
		l=l-1;
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
	bubsort(a,n);
	printf("Sorted List is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
