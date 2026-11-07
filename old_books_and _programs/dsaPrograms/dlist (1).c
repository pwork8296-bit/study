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
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
		nn->prev=NULL;
		return;
	}
	
	while(temp->next!=NULL)
	temp=temp->next;
	
	temp->next=nn;
	nn->prev=temp;
}

void addatbeg(int x)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	nn->prev=NULL;
	
	nn->next=head;
	
	if(head!=NULL)
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
		if(temp->next==NULL)
		break;
		temp=temp->next;
	}
	
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	
	nn->next=temp->next;
	nn->prev=temp;
	
	if(temp->next!=NULL)
	temp->next->prev=nn;
	
	temp->next=nn;
}


void dldelete(int x)
{
	struct node *temp=head;
	//list is empty
	if(head==NULL)
	{
		printf("List node found\n");
		return;
	}	
	
	//only one node is present
	if(head->next==NULL)
	{
		if(head->data==x)
		{
			free(head);
			head=NULL;
		}
		else
		{
			printf("Node not found\n");
		}
		return;
	}
	
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			if(temp==head)
			{
				head=temp->next;
				head->prev=NULL;
			}
			else if(temp->next==NULL)
			{
				temp->prev->next=temp->next;
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
	}
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
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
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
					dldelete(x);
					break;
			case 5:display();
					break;
			case 6:exit(0);
		}
	}
	return 0;
}
