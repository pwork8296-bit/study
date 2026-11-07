#include<stdio.h>
#include<stdlib.h>

int q[100],f=-1,r=-1,size;

void qinsert(int x)
{
	if(r==size-1)
	{
		printf("Queue overflow\n");
		return;
	}
	r++;
	q[r]=x;
	
	if(f==-1)
	f=0;
}

int qdelete()
{
	int x;
	if(f==-1)
	{
		printf("Queue underflow\n");
		return -1;
	}
	
	x=q[f];
	
	if(f==r)
	f=r=-1;
	else
	f++;
	
	return x;
}

void qdisplay()
{
	int i;
	if(f==-1)
	{
		printf("Queue is empty\n");
		return;
	}	
	for(i=f;i<=r;i++)
	{
		printf("%d ",q[i]);
	}
	printf("\n");
}

void frontelement()
{
	if(f==-1)
	printf("Queue is empty\n");
	else
	printf("Front element is %d\n",q[f]);
}


void rearelement()
{
	if(r==-1)
	printf("Queue is empty\n");
	else
	printf("Rear element is %d\n",q[r]);
}

void isfull()
{
	if(r==size-1)
	printf("Queue is full\n");
	else
	printf("Queue is not full\n");
}

void isempty()
{
	if(f==-1)
	printf("Queue is empty\n");
	else
	printf("Queue is not empty\n");
}

int sizeofqueue()
{
	if(f==-1)
	return 0;
	else
	return r-f+1;
}
int main()
{
	int ch,x,y;
	printf("Enter size <100\n");
	scanf("%d",&size);
	while(1)
	{
		printf("\n1.qinsert\n");
		printf("2.qdelete\n");
		printf("3.qdisplay\n");
		printf("4.front element\n");
		printf("5.rear element\n");
		printf("6.isfull\n");
		printf("7.isempty\n");
		printf("8.size of queue\n");
		printf("9.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter a value\n");
					scanf("%d",&x);
					qinsert(x);
					break;
			case 2:y=qdelete();
					if(y!=-1)
					printf("Deleted Value is %d\n",y);
					break;
			case 3:qdisplay();
					break;
			case 4:frontelement();
					break;
			case 5:rearelement();
					break;
			case 6:isfull();
					break;
			case 7:isempty();
					break;
			case 8:printf("Size of the queue is %d\n",sizeofqueue());
					break;			
			case 9:exit(0);
		}
	}
	return 0;
}

