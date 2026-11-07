#include<stdio.h>
int main()
{
	int n,i,flag,m;
	printf("Enter m value\n");
	scanf("%d",&m);
	for(n=2;n<=m;n++)
	{
		flag=0;
		for(i=2;i<=n/2;i++)
		{
			if(n%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		printf("%d ",n);
	}
	return 0;
}
