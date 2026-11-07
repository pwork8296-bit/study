#include<stdio.h>
int main()
{
	int a,b,g,r;
	printf("Enter the values of a and b a<b\n");
	scanf("%d %d",&a,&b);
	do
	{
		r=b%a;
		b=a;
		a=r;
	}while(a!=0);
	printf("GCD is %d\n",b);
	return 0;
}
