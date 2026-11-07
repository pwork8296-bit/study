#include<stdio.h>
int main()
{
	int n,i,flag;
	printf("Enter n value\n");
	scanf("%d",&n);
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
	printf("Prime Number\n");
	else
	printf("Composite Number\n");
	return 0;
}
