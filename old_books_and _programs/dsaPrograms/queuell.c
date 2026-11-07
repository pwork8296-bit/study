#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*f=NULL,*r=NULL;

void qinsert(int x)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	if(nn==NULL)
	{
		printf("Queue overflow\n");
		return;
	}
	nn->data=x;
	nn->next=NULL;
	
	if(f==NULL&&r==NULL)
	{
		f=r=nn;
		return;
	}
	
	r->next=nn;
	r=nn;
}

int qdelete()
{
	struct node *temp=f;
	int x;
	if(f==NULL)
	{
		printf("Queue underflow\n");
		return -1;
	}
	x=f->data;
	
	if(f==r)
	f=r=NULL;
	else
	f=temp->next;
	
	return x;
}

void qdisplay()
{
	struct node *temp=f;
	
	if(f==NULL)
	{
		printf("Queue is empty\n");
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
	int ch,x,y;
	while(1)
	{
		printf("\n1.qinsert\n");
		printf("2.qdelete\n");
		printf("3.qdisplay\n");
		printf("4.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter a value\n");
					scanf("%d",&x);
					qinsert(x);
					break;
			case 2:y=qdelete();
					if(y!=-1)
					printf("Deleted Value is %d\n",y);
					break;
			case 3:qdisplay();
					break;
			case 4:exit(0);
		}
	}
	return 0;
}

