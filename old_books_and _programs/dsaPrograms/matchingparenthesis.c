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

int matching(char s1[])
{
	int i;
	char temp;
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]=='{'||s1[i]=='['||s1[i]=='(')
		push(s1[i]);
		else
		{
			if(s1[i]=='}')
			{
				temp=pop();
				if(temp!='{')
				return 0;
			}
			if(s1[i]==']')
			{
				temp=pop();
				if(temp!='[')
				return 0;
			}
			if(s1[i]==')')
			{
				temp=pop();
				if(temp!='(')
				return 0;
			}
		}
	}
	
	if(top==-1)
	return 1;
	else
	return 0;
}

int main()
{
	int m;
	char s1[size];
	printf("Enter the expression\n");
	gets(s1);
	m=matching(s1);
	if(m==1)
	printf("true");
	else
	printf("false");
	return 0;
}
