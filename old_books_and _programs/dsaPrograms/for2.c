#include<stdio.h>
int main()
{
	int n,i,se=0,so=0;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		se=se+i;
		else
		so=so+i;
	}
	printf("%d is the even sum\n",se);
	printf("%d is the odd sum\n",so);
	return 0;
}
