#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*top=NULL;

void push(int x)
{
	struct node *nn;
	
	nn=(struct node*)malloc(sizeof(struct node));
	if(nn==NULL)
	{
		printf("Stack overflow\n");
		return;
	}
	
	nn->data=x;
	nn->next=top;
	top=nn;
}

int pop()
{
	int x;
	struct node *temp=top;
	
	if(top==NULL)
	{
		printf("Stack underflow\n");
		return -1;
	}
	
	x=top->data;
	top=temp->next;
	
	free(temp);
	return x;
}

void display()
{
	struct node *temp=top;
	
	if(top==NULL)
	{
		printf("Stack is empty\n");
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
		printf("\n1.push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter a value\n");
					scanf("%d",&x);
					push(x);
					break;
			case 2:y=pop();
					if(y!=-1)
					printf("Popped Value is %d\n",y);
					break;
			case 3:display();
					break;
			case 4:exit(0);
		}
	}
	return 0;
}

