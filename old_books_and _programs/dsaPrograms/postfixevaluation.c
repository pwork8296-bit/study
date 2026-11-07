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

int evaluate(char postfix[])
{
	int i,x,y;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(postfix[i]>='0'&&postfix[i]<='9')
		{
			push(postfix[i]-'0');
		}
		else
		{
			x=pop();
			y=pop();
			switch(postfix[i])
			{
				case '+':push(y+x);
						break;
				case '-':push(y-x);
						break;
				case '*':push(y*x);
						break;
				case '/':push(y/x);
						break;
				case '%':push(y%x);
						break;
			}
		}
	}
	return pop();
}

int main()
{
	int v;
	char postfix[size];
	top++;
	s[top]='#';
	printf("Enter postfix expression\n");
	gets(postfix);
	v=evaluate(postfix);
	printf("Value is %d\n",v);
	return 0;
}
