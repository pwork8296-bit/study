#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int data;
	struct tnode *lchild;
	struct tnode *rchild;	
};

typedef struct tnode* Node;

Node create(Node root,int x)
{
	Node nn,cur,par;
	//creation of node
	nn=(Node)malloc(sizeof(struct tnode));
	nn->data=x;
	nn->lchild=NULL;
	nn->rchild=NULL;
	
	//if bst is not present
	if(root==NULL)
	{
		root=nn;
		return root;
	}
	
	//if bst is already present
	cur=root;
	while(cur!=NULL)
	{
		par=cur;
		if(x>cur->data)
		cur=cur->rchild;
		else
		cur=cur->lchild;
	}
	if(x>par->data)
	par->rchild=nn;
	else
	par->lchild=nn;
	
	return root;
}


void preorder(Node root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void inorder(Node root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%d ",root->data);
		inorder(root->rchild);
	}
}

void postorder(Node root)
{
	if(root!=NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ",root->data);
	}
}

int maximum(Node root)
{
	Node cur=root;
	if(root==NULL)
		return -999;
	while(cur->rchild!=NULL)
		cur=cur->rchild;
	
	return cur->data;
}

int minimum(Node root)
{
	Node cur=root;
	if(root==NULL)
		return -999;
	while(cur->lchild!=NULL)
		cur=cur->lchild;
	
	return cur->data;
}

void search(Node root,int x)
{
	Node cur=root;
	while(cur!=NULL)
	{
		if(x>cur->data)
		cur=cur->rchild;
		else if(x<cur->data)
		cur=cur->lchild;
		else
		{
			printf("Element found\n");
			return;
		}
	}
	printf("Element not found\n");
}

int height(Node root)
{
	int hl,hr;
	if(root==NULL)
	return 0;
	else
	{
		hl=height(root->lchild);
		hr=height(root->rchild);
		return 1+(hl>hr?hl:hr);
	}
}

Node tdelete(Node root,int x)
{
	Node cur,par,psuc,suc,attach;
	if(root==NULL)
	{
		printf("No Binary search tree\n");
		return root;
	}
	if(root->lchild==NULL&&root->rchild==NULL)
	{
		if(root->data==x)
		{
			root=NULL;
			printf("Node deleted\n");
			return root;
		}
		else
		{
			printf("Node not found\n");
			return root;
		}
	}
	
	cur=root;
	while((cur->data!=x)&&(cur!=NULL))
	{
		par=cur;
		if(x<cur->data)
		cur=cur->lchild;
		else if(x>cur->data)
		cur=cur->rchild;
	}
	
	if(cur==NULL)
	{
		printf("Node not found\n");
		return root;
	}
	
	if(cur->lchild==NULL&&cur->rchild==NULL)
	{
		if(par->lchild==cur)
		par->lchild=NULL;
		else
		par->rchild=NULL;
		printf("Node deleted\n");
		return root;
	}
	
	if(cur->rchild==NULL)
	{
		attach=cur->lchild;
	}
	else if(cur->lchild==NULL)
	{
		attach=cur->rchild;
	}
	else
	{
		psuc=cur;
		suc=cur->rchild;
		while(suc->lchild!=NULL)
		{
			psuc=suc;
			suc=suc->lchild;
		}
		if(psuc==cur)
		{
			suc->lchild=cur->lchild;
		}
		else
		{
			suc->lchild=cur->lchild;
			psuc->lchild=suc->rchild;
			suc->rchild=cur->rchild;
		}
		attach=suc;
	}
	
	if(cur==root)
	{
		root=attach;
	}
	else if(par->lchild==cur)
	{
		par->lchild=attach;
	}
	else
	{
		par->rchild=attach;
	}
	printf("Node deleted\n");
	return root;
}

int main()
{
	int x,ch;
	Node root=NULL;
	while(1)
	{
		printf("\n1.create\n");
		printf("2.preorder\n");
		printf("3.inorder\n");
		printf("4.postorder\n");
		printf("5.Maximum\n");
		printf("6.Minimum\n");
		printf("7.Search\n");
		printf("8.height\n");
		printf("9.Delete\n");
		printf("10.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter a value\n");
					scanf("%d",&x);
					root=create(root,x);
					break;
			case 2:preorder(root);
					printf("\n");
					break;
			case 3:inorder(root);
					break;
			case 4:postorder(root);
					break;
			case 5:printf("The maximum value is %d\n",maximum(root));
					break;
			case 6:printf("The minimum value is %d\n",minimum(root));
					break;
			case 7:printf("Enter a value to search\n");
					scanf("%d",&x);
					search(root,x);
					break;
			case 8:printf("Height of the tree is %d\n",height(root));
					break;
			case 9:printf("Enter a value to delete\n");
					scanf("%d",&x);
					root=tdelete(root,x);
					break;
			case 10:exit(0);
		}
	}
	return 0;
}


