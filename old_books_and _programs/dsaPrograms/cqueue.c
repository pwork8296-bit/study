#include<stdio.h>
#include<stdlib.h>

int *cq,f=-1,r=-1,size;

void cqinsert(int x)
{
	if((f==0&&r==size-1)||(f==r+1))
	{
		printf("CQueue overflow\n");
		return;
	}
	if(r==size-1)
	r=0;
	else
	r++;
	cq[r]=x;
	
	if(f==-1)
	f=0;
}

int cqdelete()
{
	int x;
	if(f==-1)
	{
		printf("Queue underflow\n");
		return -1;
	}
	
	x=cq[f];
	if(f==size-1)
	f=0;
	else if(f==r)
	f=r=-1;
	else
	f++;
	
	return x;
}

void cqdisplay()
{
	int i;
	if(f==-1)
	{
		printf("Queue is empty\n");
		return;
	}	
	if(f<=r)
	{
		for(i=f;i<=r;i++)
		{
			printf("%d ",cq[i]);
		}
	}
	else
	{
		for(i=f;i<=size-1;i++)
		{
			printf("%d ",cq[i]);
		}	
		for(i=0;i<=r;i++)
		{
			printf("%d ",cq[i]);
		}
	}

	printf("\n");
}

void frontelement()
{
	if(f==-1)
	printf("Queue is empty\n");
	else
	printf("Front element is %d\n",cq[f]);
}


void rearelement()
{
	if(r==-1)
	printf("Queue is empty\n");
	else
	printf("Rear element is %d\n",cq[r]);
}

void isfull()
{
	if((f==0&&r==size-1)||(f==r+1))
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
	int i,ct=0;
	if(f==-1)
	return 0;
	else if(f<=r)
	return r-f+1;
	else
	{
		for(i=f;i<=size-1;i++)
		{
			ct++;
		}	
		for(i=0;i<=r;i++)
		{
			ct++;
		}
		return ct;
	}
}
int main()
{
	int ch,x,y;
	printf("Enter size\n");
	scanf("%d",&size);
	cq=(int*)malloc(size*sizeof(int));
	
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
					cqinsert(x);
					break;
			case 2:y=cqdelete();
					if(y!=-1)
					printf("Deleted Value is %d\n",y);
					break;
			case 3:cqdisplay();
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

