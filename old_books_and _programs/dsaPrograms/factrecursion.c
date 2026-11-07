#include<stdio.h>

unsigned long int fact(int n)
{
	if(n==0)
	return 1;
	else
	return n*fact(n-1);
}

int main()
{
	unsigned long int f;
	int n;
	printf("Enter n value\n");
	scanf("%d",&n);
	f=fact(n);
	printf("Factorial is %lu",f);
	return 0;
}
