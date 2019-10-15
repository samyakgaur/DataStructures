//Expression Tree
#include<stdio.h>
#include<stdlib.h>
#define max 10
struct node
{
	char info;
	struct node *left, *right;
};
struct node *ROOT=NULL;
struct node * getnode(int x)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->info=x;
	new->left=NULL;
	new->right=NULL;
	return new;
}
//Inorder Traversal
void Inorder(struct node *t)
{
	if(t!=NULL)
	{
		Inorder(t->left);
		printf("%c",t->info);
		Inorder(t->right);
	}
}
struct stack		//Initialise Stack
{
	struct node *a[max];
	int top;
};
void push(struct stack *s, struct node *p)	//Push operation
{
	s->a[++s->top]=p;
}
struct node * pop(struct stack *s)		//Pop operation
{
	return (s->a[s->top--]);
}
int isoperand(char x)		//check for operand
{
	switch(x)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return 0;
		default:
			return 1;
	}
}
void main()
{
	struct stack s;
	char exp[max];
	int i=0;
	struct node *new,*t1,*t2;
	s.top=-1;
	printf("Enter the postfix expression:\n");
	gets(exp);
	while(exp[i]!='\0')		//loop till end of string
	{
		new=getnode(exp[i]);
		if(isoperand(exp[i]))
			push(&s,new);
		else
		{
			t1=pop(&s);
			t2=pop(&s);
			new->right=t1;
			new->left=t2;
			push(&s,new);
		}
		i++;
	}
	ROOT=pop(&s);	//pop root node
	printf("Inorder expression:\n");
	Inorder(ROOT);
	printf("\n");
}	
	
/*
OUTPUT:
Enter the postfix expression:
ab+cd-*
Inorder expression:
a+b*c-d
*/

