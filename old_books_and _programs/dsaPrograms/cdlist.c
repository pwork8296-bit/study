#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head=NULL;

void create(int x)
{
	struct node *nn,*temp=head;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	if(head==NULL)
	{
		head=nn;
		head->next=nn;
		head->prev=nn;
		return;
	}
	
	//moving to the last node
	
	temp=head->prev;
	
	temp->next=nn;
	nn->prev=temp;
	nn->next=head;
	head->prev=nn;
}

void addatbeg(int x)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	
	if(head==NULL)
	{
		head=nn;
		head->prev=nn;
		head->next=nn;
		return;
	}
	
	head->prev->next=nn;
	nn->prev=head->prev;
	nn->next=head;
	head->prev=nn;
	
	head=nn;
}

void addatpos(int x,int p)
{
	struct node *temp=head,*nn;
	int i;
	
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
	nn->prev=temp;
	temp->next->prev=nn;
	temp->next=nn;
}


void cdldelete(int x)
{
	struct node *temp=head,*t;
	//list is empty
	if(head==NULL)
	{
		printf("List node found\n");
		return;
	}	
	
	//only one node is present
	if(head->next==head&&head->prev==head)
	{
		if(head->data==x)
		{
			free(head);
			printf("Node deleted\n");
			head=NULL;
		}
		else
		{
			printf("Node not found\n");
		}
		return;
	}
	
	do
	{
		if(temp->data==x)
		{
			if(temp==head)
			{
				t=head->prev;
				head=temp->next;
				head->prev=t;
				t->next=head;
			}
			else
			{
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
			}
			free(temp);
			printf("Node deleted\n");
			return;
		}
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
					cdldelete(x);
					break;
			case 5:display();
					break;
			case 6:exit(0);
		}
	}
	return 0;
}
