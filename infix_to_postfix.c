/*
Samyak Gaur(8604)
Batch B

A program to convert an infix expression to postfix expression 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 5
struct stack{
	char a[max];
	int top;
}; //End of structure 
void push(struct stack *p,char x)
{
	if(p->top==max)
		printf("Stack overflow");
	else{
		p->top++;
		p->a[p->top]=x;
	}//end of else condition
}//End of push function  
char pop(struct stack *p)
{
	if(p->top==-1){
		printf("Stack underflow");
		printf("The popped value is: -1 \n");
	}//End of if condition
	else
		return(p->a[p->top--]);
}//End of pop function  
int isEmpty(struct stack *p)
{
	if(p->top==-1)
		return 1;
	else{
		return 0;
	}//end of else condition
}//End of isEmpty function  
char peep(struct stack *p)
{
	if(p->top==-1){
		//printf("Stack Underflow");
		return 'c';}
	else{
		return(p->a[p->top]);
	}//end of else condition
}//End of peep function 
int isoperand(char x){
	if(x>='0' && x<='9')
		return 1;
	else
		return 0;
}//End of isoperand function  
int priority(char x)
{
	 if(x=='(')
	 return 0;
	 else if (x=='+' || x=='-')
	 return 1;
	 else if (x=='*' || x=='/')
	 return 2;
	 else
	 	return 3;
}

int main(){
	int i=0,n1,n2,j=0;
	char exp[50],pos[20],x;
	struct stack s;
	s.top=-1;
	printf("Enter an expression: ");
	gets(exp);
	for(i=0;exp[i]!='\0';i++){
		if(isoperand(exp[i]))
			{
				pos[j]=exp[i];
				j++;
			}
			
		else if (exp[i] =='(')
			push(&s,exp[i]);
		else if (exp[i]==')')
		{
			while((x=pop(&s))!='(')
			{
				pos[j]=x;
				j++;
			}//End of while loop 
			
		}//End of if condition
		else
			{
				while(priority(exp[i])<=priority(peep(&s)) && !isEmpty(&s))
					{
						x=pop(&s);
						pos[j]=x;
						j++;
					}
				push(&s,exp[i]);
			}//End if else case
		}//End of for loop 
		while(!isEmpty(&s))
			{
				x=pop(&s);
				pos[j]=x;
				j++;
			}
			pos[j]='\0';
			puts(pos);
		
		return(0);
	}//End of main
/*
Output of the following code is:
(base) Samyaks-Air:DataStructures samyakgaur$ ./a
warning: this program uses gets(), which is unsafe.
Enter an expression: 4+5
45+
(base) Samyaks-Air:DataStructures samyakgaur$ ./a
warning: this program uses gets(), which is unsafe.
Enter an expression: 8+4-9*2
84+92*-
*/
