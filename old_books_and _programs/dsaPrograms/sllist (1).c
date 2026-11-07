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
	nn->next=NULL;
	
	if(head==NULL)
	{
		head=nn;
		return;
	}
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=nn;
}

void addatbeg(int x)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	nn->next=head;
	head=nn;
}

void addatpos(int x,int p)
{
	int i;
	struct node *temp=head,*nn;
	for(i=1;i<p-1;i++)
	{
		if(temp->next==NULL)
		break;
		temp=temp->next;
	}
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	nn->next=temp->next;
	temp->next=nn;
}

void ldelete(int x)
{
	struct node *temp=head,*prev;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			if(temp==head)
			{
				head=temp->next;
			}
			else
			{
				prev->next=temp->next;
			}
			printf("Node deleted\n");
			free(temp);
			return;			
		}
		prev=temp;
		temp=temp->next;
	}
	printf("Element not found\n");
}

void deletebypos(int p)
{
	int i;
	struct node *temp=head,*prev;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(p<=0)
	{
		printf("Invalid Position\n");
		return;
	}
	if(p==1)
	{
		head=temp->next;
		printf("Node deleted\n");
		free(temp);
		return;
	}
	for(i=1;i<p;i++)
	{
		if(temp==NULL)
		{
			printf("Position not found\n");
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	printf("Node deleted\n");
	free(temp);	
}

void search(int x)
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			printf("Node found\n");
			return;
		}
		temp=temp->next;
	}
	printf("Node not found\n");
}

void reverse()
{
	struct node *temp=head,*cur=head,*prev=NULL;
	while(temp!=NULL)
	{
		temp=temp->next;
		cur->next=prev;
		prev=cur;
		cur=temp;
	}
	head=prev;
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
		printf("4.deletebyvalue\n");
		printf("5.deletebypos\n");
		printf("6.search\n");
		printf("7.reverse\n");
		printf("8.display\n");
		printf("9.exit\n");
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
					ldelete(x);
					break;
			case 5:printf("Enter a position\n");
					scanf("%d",&p);
					deletebypos(p);
					break;
			case 6:printf("Enter a value\n");
					scanf("%d",&x);
					search(x);
					break;
			case 7:reverse();
					break;
			case 8:display();
					break;
			case 9:exit(0);	
		}
	}
	return 0;
}
