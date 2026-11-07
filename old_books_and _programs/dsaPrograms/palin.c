#include<stdio.h>
int main()
{
	int n,r,rev=0,m;
	printf("Enter n value\n");
	scanf("%d",&n);
	m=n;
	do
	{
		r=n%10;
		rev=rev*10+r;
		n=n/10;
	}while(n>0);
	if(rev==m)
	printf("Palindrome\n");
	else
	printf("Not a Palindrome\n");
	return 0;
}
