#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*f=NULL,*r=NULL;


void dqinsertrear(int x)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	if(nn==NULL)
	{
		printf("Dqueue overflow\n");
		return;
	}
	nn->data=x;
	nn->next=NULL;
	
	if(f==NULL&&r==NULL)
	{
		nn->prev=NULL;
		f=r=nn;
		return;
	}
	
	r->next=nn;
	nn->prev=r;
	r=nn;
}

void dqinsertfront(int x)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	if(nn==NULL)
	{
		printf("Dqueue overflow\n");
		return;
	}
	nn->data=x;
	nn->prev=NULL;
	
	if(f==NULL&&r==NULL)
	{
		nn->next=NULL;
		f=r=nn;
		return;
	}
	
	nn->next=f;
	f->prev=nn;
	f=nn;
}


int dqdeleterear()
{
	struct node *temp=r;
	int x;
	if(r==NULL)
	{
		printf("Dqueue is empty\n");
		return -1;
	}
	x=r->data;
	if(f==r)
	f=r=NULL;
	else
	{
		r=temp->prev;
		r->next=NULL;
	}
	free(temp);
	return x;
}

int dqdeletefront()
{
	struct node *temp=f;
	int x;
	if(f==NULL)
	{
		printf("Dqueue is empty\n");
		return -1;
	}
	x=f->data;
	
	if(f==r)
	f=r=NULL;
	else
	{
		f=temp->next;
		f->prev=NULL;
	}
	free(temp);
	return x;
}


void dqdisplay()
{
	struct node *temp=f;
	
	if(f==NULL)
	{
		printf("DQueue is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int x,y,ch;
	while(1)
	{
		printf("\n1.insertrear\n");
		printf("2.insertfront\n");
		printf("3.deleterear\n");
		printf("4.deletefront\n");
		printf("5.display\n");
		printf("6.exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter a value\n");
					scanf("%d",&x);
					dqinsertrear(x);
					break;
			case 2:printf("Enter a value\n");
					scanf("%d",&x);
					dqinsertfront(x);
					break;
			case 3:y=dqdeleterear();
					if(y!=-1)
					printf("Deleted value is %d\n",y);
					break;
			case 4:y=dqdeletefront();
					if(y!=-1)
					printf("Deleted value is %d\n",y);
					break;
			case 5:dqdisplay();
					break;
			case 6:exit(0);			
		}
	}
}

