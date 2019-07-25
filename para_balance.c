/*
Samyak Gaur(8604)
Batch B

A program to evaluate for a balanced expression  
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 5
struct stack{
	float a[max];
	int top;
}; //End of structure 
void push(struct stack *p,int x)
{
	if(p->top==max)
		printf("Stack overflow");
	else{
		p->top++;
		p->a[p->top]=x;
	}//end of else condition
}//End of push function  
float pop(struct stack *p)
{
	if(p->top==-1){
		printf("Stack underflow");
		printf("The popped value is: -1 \n");
	}//End of if condition
	else
		return(p->a[p->top--]);
}//End of pop function  

int isopening(char x){
	if(x=='{' || x=='[' || x=='(')
		return 1;
	else
		return 0;
}//End of isoperand function
int isclosing(char x){
	if(x=='}' || x==']' || x==')')
		return 1;
	else
		return 0;
}//End of isoperand function  
int isEmpty(struct stack *p)
{
	if(p->top==-1)
		return 1;
	else{
		return 0;
	}//end of else condition
}//End of isEmpty function  
int match(char b , char a)
{
	if(a=='{' && b=='}')
		return 1;
	if(a=='[' && b==']')
		return 1;
	if(a=='(' && b==')')
		return 1;
	else 
		return 0;
}

int main(){
	int i,n1,n2=3;
	char exp[50];
	struct stack s;
	s.top=-1;
	printf("Enter an expression: ");
	gets(exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(isopening(exp[i]))
			push(&s,exp[i]);
		if (isclosing(exp[i]))
		{
			n1=pop(&s);
			if(!match(exp[i],n1))
			{
				printf("Expression unbalanced \n");
				break;
			}//End  of if condition
		}//End of if part
	}//End of for loop 
	if(isEmpty(&s))
	printf("Balanced expression\n");
	else
	printf("UnBalanced expression\n");
	return(0);
	}//End of main
