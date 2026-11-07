#include<stdio.h>
int main()
{
	int n,i,s;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++)
	{
		s=s+i;
	}
	printf("%d is the sum\n",s);
	return 0;
}
