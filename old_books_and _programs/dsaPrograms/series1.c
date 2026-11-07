//1+x+x^2/2!+x^3/3!+......
#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,x;
	unsigned long int f;
	double s=1.0;
	
	printf("Enter x and n values\n");
	scanf("%d %d",&x,&n);
	
	for(i=1;i<=n;i++)
	{
		f=1;
		for(j=1;j<=i;j++)
		{
			f=f*j;
		}
		s=s+pow(x,i)/f;
	}
	
	printf("Sum is %lf",s);
	return 0;
}
