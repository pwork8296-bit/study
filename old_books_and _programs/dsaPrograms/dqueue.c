#include<stdio.h>
#include<stdlib.h>
int size, *dq,f=-1,r=-1;

void dqinsertrear(int x)
{
	if(r==size-1)
	{
		printf("DQueue is full\n");
		return;
	}
	r++;
	dq[r]=x;
	
	if(f==-1)
	f=0;
}


void dqinsertfront(int x)
{
	if(f==0)
	{
		printf("Dqueue is full\n");
		return;
	}
	
	if(f==-1)
	f=r=0;
	else
	f--;
	
	dq[f]=x;
}



int dqdeleterear()
{
	int x;
	if(r==-1)
	{
		printf("Dqueue is empty\n");
		return -1;
	}
	
	x=dq[r];
	
	if(f==r)
	f=r=-1;
	else
	r--;
	
	return x;
}

int dqdeletefront()
{
	int x;
	if(f==-1)
	{
		printf("Dqueue is empty\n");
		return -1;
	}
	
	x=dq[f];
	
	if(f==r)
	f=r=-1;
	else
	f++;
	
	return x;
}

void dqdisplay()
{
	int i;
	if(f==-1||r==-1)
	{
		printf("Dqueue is empty\n");
		return;
	}
	
	for(i=f;i<=r;i++)
	{
		printf("%d ",dq[i]);
	}
	printf("\n");
}


void dqisfull()
{
	if(f==0&&r==size-1)
	printf("Dqueue is full\n");
	else
	printf("Dqueue is not full\n");	
}

void dqisempty()
{
	if(f==-1||r==-1)
	printf("Dqueue is empty\n");
	else
	printf("Dqueue is not empty\n");
}

int sizeofdqueue()
{
	if(f==-1||r==-1)
	return 0;
	else
	return r-f+1;
}

void dqfrontelement()
{
	if(f==-1||r==-1)
	printf("Dqueue is empty\n");
	else
	printf("Front Element is %d\n",dq[f]);
}


void dqrearelement()
{
	if(f==-1||r==-1)
	printf("Dqueue is empty\n");
	else
	printf("Rear Element is %d\n",dq[r]);
}


int main()
{
	int x,y,ch;
	printf("Enter size\n");
	scanf("%d",&size);
	dq=(int*)malloc(sizeof(int)*size);
	while(1)
	{
		printf("\n1.insertrear\n");
		printf("2.insertfront\n");
		printf("3.deleterear\n");
		printf("4.deletefront\n");
		printf("5.display\n");
		printf("6.size\n");
		printf("7.isfull\n");
		printf("8.isempty\n");
		printf("9.frontelement\n");
		printf("10.rearelement\n");
		printf("11.exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter a value\n");
					scanf("%d",&x);
					dqinsertrear(x);
					break;
			case 2:printf("Enter a value\n");
					scanf("%d",&x);
					dqinsertfront(x);
					break;
			case 3:y=dqdeleterear();
					if(y!=-1)
					printf("Deleted value is %d\n",y);
					break;
			case 4:y=dqdeletefront();
					if(y!=-1)
					printf("Deleted value is %d\n",y);
					break;
			case 5:dqdisplay();
					break;
			case 6:printf("The number of elements in dqueue is %d\n",sizeofdqueue());
					break;
			case 7:dqisfull();
					break;
			case 8:dqisempty();
					break;
			case 9:dqfrontelement();
					break;
			case 10:dqrearelement();
					break;
			case 11:exit(0);			
		}
	}
}

