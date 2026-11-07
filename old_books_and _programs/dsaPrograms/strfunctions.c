#include<stdio.h>
#include<string.h>
int main()
{
	int l,c;
	char s1[100],s2[100],s3[100];
	printf("Enter string1\n");
	gets(s1);
	
	printf("Enter string3\n");
	gets(s3);
	//l=strlen(s1);
	//printf("Length of the string is %d\n",l);
	
	strcpy(s2,s1);
	printf("Copied String is %s\n",s2);
	
	strrev(s2);
	
	printf("Reversed string is %s\n",s2);
	
	//strcat(s1,s3);
	
	//printf("Concatenated String is %s\n",s1);
	
	c=stricmp(s1,s3);
	printf("Difference between the strings is %d\n",c);
	
	strlwr(s1);
	strupr(s3);
	printf("%s %s\n",s1,s3);
	
	strset(s3,'$');
	printf("%s\n",s3);
	
	return 0;
}
