#include<stdio.h>
#include<stdlib.h>

#define size 5

int s[size],top=-1;

void push(int x)
{
	if(top==size-1)
	{
		printf("Stack is overflow\n");
		return;
	}
	top++;
	s[top]=x;		
}

int pop()
{
	int x;
	if(top==-1)
	{
		printf("Stack underflow\n");
		return -1;	
	}	
	x=s[top];
	top--;
	return x;
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty\n");
		return;
	}	
	for(i=top;i>=0;i--)
	{
		printf("%d ",s[i]);
	}
	printf("\n");
}

int sizeofstack()
{
	return top+1;
}

int peek()
{
	if(top==-1)
		return -1;
	else
		return s[top];
}

int isfull()
{
	if(top==size-1)
	return 1;
	else
	return 0;
}

int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}

int main()
{
	int ch,x,y,m,n;
	while(1)
	{
		printf("\n1.push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.size\n");
		printf("5.peek\n");
		printf("6.isfull\n");
		printf("7.isempty\n");
		printf("8.exit\n");
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
			case 4:printf("Size of the stack is %d\n",sizeofstack());
					break;
			case 5:printf("The top most element is %d\n",peek());
					break;
			case 6:m=isfull();
					if(m==1)
					printf("Stack is full\n");
					else
					printf("Stack is not full\n");
					break;
			case 7:n=isempty();
					if(n==1)
					printf("Stack is empty\n");
					else
					printf("Stack is not empty\n");
					break;
			case 8:exit(0);
		}
	}
	return 0;
}

