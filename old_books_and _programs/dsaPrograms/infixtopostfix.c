#include<stdio.h>

#define size 30

char s[size];
int top=-1;

void push(char ch)
{
	top++;
	s[top]=ch;
}

char pop()
{
	char ch;
	ch=s[top];
	top--;
	return ch;
}

int priority(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':
		case '%':return 2;
		case '#':return 0;
		default:return 3;
	}
}

void convert(char infix[],char postfix[])
{
	int i=0,j=0;
	
	while(infix[i]!='\0')
	{
		while(priority(infix[i])<=priority(s[top]))
		{
			postfix[j]=pop();
			j++;
		}
		push(infix[i]);
		i++;
	}
	while(s[top]!='#')
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
}

int main()
{
	char infix[size],postfix[size];
	top++;
	s[top]='#';
	printf("Enter infix expression\n");
	gets(infix);
	convert(infix,postfix);
	printf("Postfix expression is %s\n",postfix);
	return 0;
}
		

