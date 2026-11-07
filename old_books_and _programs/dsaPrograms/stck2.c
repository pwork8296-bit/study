#include<stdio.h>
#include<stdlib.h>

int s[100],top=-1,size;

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

int main()
{
	int ch,x,y;
	printf("Enter size <100\n");
	scanf("%d",&size);
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

