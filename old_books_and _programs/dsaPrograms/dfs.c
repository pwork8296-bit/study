#include<stdio.h>
#define size 20
int visited[size],a[size][size];

void dfs(int v,int n)
{
	int i;
	visited[v]=1;
	printf("%d\t",v);
	for(i=1;i<=n;i++)
	{
		if(a[v][i]==1&&visited[i]==0)
		{
			dfs(i,n);
		}
	}
}

int main()
{
	int n,i,j,v;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Enter the source vertex\n");
	scanf("%d",&v);
	
	dfs(v,n);
	
	return 0;
}


