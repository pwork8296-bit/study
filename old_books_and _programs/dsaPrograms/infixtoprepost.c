#include<stdio.h>
#include<string.h>
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

void intopost(char infix[],char postfix[])
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

void intopre(char infix[],char prefix[])
{
	int i=0,j=0;
	strrev(infix);
	while(infix[i]!='\0')
	{
		while(priority(infix[i])<=priority(s[top]))
		{
			prefix[j]=pop();
			j++;
		}
		push(infix[i]);
		i++;
	}
	while(s[top]!='#')
	{
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
	strrev(prefix);
}

int isoperator(char ch)
{
	if(ch=='+'||ch=='*'||ch=='-'||ch=='/'||ch=='%')
	return 1;
	else
	return 0;
}

void pretoin(char prefix[],char infix[])
{
	int i,j=0;
	char temp;
	for(i=0;prefix[i]!='\0';i++)
	{
		if(isoperator(prefix[i]))
		push(prefix[i]);
		else
		{
			infix[j++]=prefix[i];
			temp=pop();
			if(isoperator(temp))
			infix[j++]=temp;	
		}	
	}
	infix[j]='\0';	
}

void posttoin(char postfix[],char infix[])
{
	int i,j=0;
	char temp;
	strrev(postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isoperator(postfix[i]))
		push(postfix[i]);
		else
		{
			infix[j++]=postfix[i];
			temp=pop();
			if(isoperator(temp))
			infix[j++]=temp;	
		}	
	}
	infix[j]='\0';
	strrev(infix);	
}

void pretopost(char prefix[],char postfix[])
{
	char infix[size];
	pretoin(prefix,infix);
	top++;
	s[top]='#';
	intopost(infix,postfix);	
}

void posttopre(char postfix[],char prefix[])
{
	char infix[size];
	posttoin(postfix,infix);
	top++;
	s[top]='#';
	intopre(infix,prefix);	
}
int main()
{
	char infix[size],postfix[size],prefix[size];
	top++;
	s[top]='#';
	/*printf("Enter infix expression\n");
	gets(infix);
	intopost(infix,postfix);
	printf("Postfix expression is %s\n",postfix);
	
	intopre(infix,prefix);
	printf("Prefix expression is %s\n",prefix);
	
	printf("Enter prefix expression\n");
	gets(prefix);
	
	pretoin(prefix,infix);
	printf("Infix expression is %s\n",infix);
	
	top++;
	s[top]='#';
	printf("Enter postfix expression\n");
	gets(postfix);
	posttoin(postfix,infix);
	printf("Infix expression is %s\n",infix);*/
	
	printf("Enter prefix expression\n");
	gets(prefix);
	pretopost(prefix,postfix);
	printf("Postfix expression is %s\n",postfix);
	
	printf("Enter postfix expression\n");
	gets(postfix);
	posttopre(postfix,prefix);
	printf("Prefix expression is %s\n",prefix);
		
	return 0;
}
		

