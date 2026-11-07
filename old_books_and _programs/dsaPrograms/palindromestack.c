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

void checkpalindrome(char s1[])
{
	int l,i;
	l=strlen(s1);
	for(i=0;i<l/2;i++)
	{
		push(s1[i]);
	}
	if(l%2!=0)
	i++;
	for(;s1[i]!='\0';i++)
	{
		if(s1[i]!=pop())
		{
			printf("Not a Palindrome\n");
			return;
		}
	}
	printf("Palindrome\n");
}

int main()
{
	char s1[size];
	printf("Enter a string\n");
	gets(s1);
	checkpalindrome(s1);
	return 0;
}
