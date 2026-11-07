#include<stdio.h>
int main()
{
	int n,i,s,m;
	printf("Enter m value\n");
	scanf("%d",&m);
	for(n=1;n<=m;n++)
	{
		s=0;
		for(i=1;i<=n;i++)
		{
			if(n%i==0)
				s=s+i;
		}
		if(s==2*n)
		printf("%d ",n);
	}
	return 0;
}
