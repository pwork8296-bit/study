#include<stdio.h>
#define size 20
int f=-1,r=-1,q[size],visited[size],a[size][size];

void qinsert(int x)
{
	r++;
	q[r]=x;
	if(f==-1)
	f=0;
}

int qdelete()
{
	int x;
	if(f==-1)
	return 0;
	x=q[f];
	if(f==r)
	f=r=-1;
	else
	f++;
	return x;
}

void bfs(int v,int n)
{
	int u,i,x;
	qinsert(v);
	visited[v]=1;
	u=v;
	while(1)
	{
		for(i=1;i<=n;i++)
		{
			if(a[u][i]==1&&visited[i]==0)
			{
				qinsert(i);
				visited[i]=1;
			}
		}
		x=qdelete();
		if(x!=0)
			printf("%d\t",x);
		if(f==-1)
			break;
		else
		u=q[f];
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
	
	bfs(v,n);
	
	return 0;
}


