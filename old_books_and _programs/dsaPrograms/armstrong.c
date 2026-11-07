#include<stdio.h>
#include<math.h>
int main()
{
	int n,m,s=0,r,x,ct;
	printf("Enter a number\n");
	scanf("%d",&n);
	m=n;
	x=n;
	while(x>0)
	{
		ct++;
		x=x/10;
	}
	while(n>0)
	{
		r=n%10;
		s=s+pow(r,ct);
		n=n/10;
	}
	if(s==m)
	printf("Armstrong\n");
	else
	printf("Not an Armstrong\n");
	return 0;
}
