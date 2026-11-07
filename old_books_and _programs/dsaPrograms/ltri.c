#include<stdio.h>
int main()
{
	int a[10][10],r1,c1,i,j;
	printf("Enter order of first matrix\n");
	scanf("%d %d",&r1,&c1);
	printf("Enter first matrix\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		
	
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				if(i<j)
				a[i][j]=0;
			}
		}
		
		printf("Lower triangular matrix is\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	
	return 0;
}
