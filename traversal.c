#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//Program to create Binary Tree with manual entry of node data

struct node
{
	char data;
	struct node *left;
	struct node *right;
};


struct node* createnode()
{
	char data;
	printf("\nEnter the data (or  ` for no data) : ");
	scanf("%c", &data);
	fflush(stdin);
	if(data == '`')return NULL;
	struct node temp = (struct node)malloc(sizeof(struct node));
	temp -> data = data;
	printf("\nEnter the left child of %c :", data);
	temp -> left = createnode();
	printf("\nEnter the right child of %c :", data);
	temp -> right = createnode();


	return temp;	
}


void inorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		inorder(ptr -> left);
		printf("%c", ptr->data);
		inorder(ptr -> right);
	}
}


void preorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		printf("%c", ptr -> data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		postorder(ptr -> left);
		postorder(ptr -> right);
		printf("%c", ptr -> data);
	}
}


int main()
{

	struct node *exp;
	exp = createnode();
	
	printf("\nInorder Traversal : ");
	inorder(exp);
	printf("\nPreorder Traversal : ");
	preorder(exp);
	printf("\nPostorder Traversal : ");
	postorder(exp);
	return 0;
}
