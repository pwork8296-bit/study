#include<stdio.h>
int main()
{
	int n,i,a,b,c;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	a=0;
	b=1;
	if(n<=1)
	{
		printf("%d ",a);
		return 0;
	}
	printf("%d %d ",a,b);
	for(i=3;i<=n;i++)
	{
		c=a+b;
		printf("%d ",c);
		a=b;
		b=c;
	}
	return 0;
}
