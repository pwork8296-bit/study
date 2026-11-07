#include<stdio.h>
int main()
{
	int n,i;
	unsigned long int f=1;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	printf("Factorial is %lu\n",f);
	return 0;
}
