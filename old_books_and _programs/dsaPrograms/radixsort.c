#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head[10];

struct node* append(struct node* n,int x)
{
	struct node *nn,*temp=n;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	nn->next=NULL;
	if(n==NULL)
	{
		n=nn;
		return n;
	}
	while(temp->next!=NULL)
	temp=temp->next;
	
	temp->next=nn;
	return n;
}

int count(int a[],int n)
{
	int max=a[0],i,ct=0;
	
	for(i=1;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	while(max>0)
	{
		max=max/10;
		ct++;
	}
	return ct;	
}

int digit(int x,int p)
{
	int i=1;
	while(i<p)
	{
		x=x/10;
		i++;
	}
	return x%10;
}

void rsort(int a[],int n)
{
	int i,ct,j,k,p,m;
	struct node *cur;
	
	for(i=0;i<10;i++)
	{
		head[i]=NULL;
	}
	ct=count(a,n);
	for(p=1;p<=ct;p++)
	{
		for(j=0;j<n;j++)
		{
			k=digit(a[j],p);
			head[k]=append(head[k],a[j]);
		}
		for(i=0,m=0;i<10;i++)
		{
			cur=head[i];
			while(cur!=NULL)
			{
				a[m]=cur->data;
				m++;
				cur=cur->next;
			}
			head[i]=NULL;
		}
	}
}

int main()
{
	int a[100],n,i;
	printf("Enter array size\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	rsort(a,n);
	printf("Sorted List is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
