#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL;

void create(int x)
{
	struct node *nn,*temp=head;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	
	if(head==NULL)
	{
		head=nn;
		nn->next=head;
		return;
	}
	
	while(temp->next!=head)
	temp=temp->next;
	
	temp->next=nn;
	nn->next=head;
}

void addatbeg(int x)
{
	struct node *nn,*t=head;
	
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	
	if(head==NULL)
	{
		head=nn;
		nn->next=head;
		return;
	}
	
	while(t->next!=head)
	t=t->next;
	
	nn->next=head;
	head=nn;
	
	t->next=head;
}

void addatpos(int x,int p)
{
	int i;
	struct node *nn,*temp=head;
	if(p<=1)
	{
		addatbeg(x);
		return;
	}
	for(i=1;i<p-1;i++)
	{
		if(temp->next==head)
		break;
		temp=temp->next;
	}
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	nn->next=temp->next;
	temp->next=nn;
}

void cldelete(int x)
{
	struct node *temp=head,*t=head,*prev;
	
	do
	{
		if(temp->data==x)
		{
			if(temp==head)
			{
				while(t->next!=head)
				t=t->next;
				head=temp->next;
				t->next=head;
			}
			else
			{
				prev->next=temp->next;
			}
			free(temp);
			printf("Node deleted\n");
			return;
		}
		prev=temp;
		temp=temp->next;		
	}while(temp!=head);
	printf("Node not found\n");
}

void display()
{
	struct node *temp=head;
	
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}

int main()
{
	int x,ch,p;
	while(1)
	{
		printf("\n1.create\n");
		printf("2.addatbeg\n");
		printf("3.addatpos\n");
		printf("4.delete\n");
		printf("5.display\n");
		printf("6.exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter a value\n");
					scanf("%d",&x);
					create(x);
					break;
			case 2:printf("Enter a value\n");
					scanf("%d",&x);
					addatbeg(x);
					break;
			case 3:printf("Enter a value and position\n");
					scanf("%d %d",&x,&p);
					addatpos(x,p);
					break;
			case 4:printf("Enter a value\n");
					scanf("%d",&x);
					cldelete(x);
					break;
			case 5:display();
					break;
			case 6:exit(0);
		}
	}
	return 0;
}
