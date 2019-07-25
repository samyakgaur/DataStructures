/*
Samyak Gaur(8604)
Batch B

A program to evaluate a postfix expression 
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
	else{
		
		return(p->a[p->top--]);
		
	}//end of else condition
}//End of pop function  

int isoperand(char x){
	if(x>='0' && x<='9')
		return 1;
	else
		return 0;
}//End of isoperand function  

int main(){
	int i,n1,n2;
	char exp[50];
	struct stack s;
	s.top=-1;
	printf("Enter an expression: ");
	gets(exp);
	for(i=0;exp[i]!='\0';i++){
		if(isoperand(exp[i]))
			push(&s,exp[i]-'0');
		else{
			n2=pop(&s);
			n1=pop(&s);
			switch(exp[i])
				{
					case '+':
							push(&s,n1+n2);
							break;
					case '-':
							push(&s,n1-n2);
							break;
					case '*':
							push(&s,n1*n2);
							break;
					case '/':
							push(&s,n1/n2);
							break;
				} //End of switch case
			}//End of else part
		}//End of for loop 
		printf("Result %f\n",pop(&s));
		return(0);
	}//End of main
/*
Output of the following code is:
universe@dell3:~/Desktop/8604$ ./a.out
Enter an expression: 45+
Result 9.000000
universe@dell3:~/Desktop/8604$ ./a.out
Enter an expression: 53*8-
Result 7.000000
*/
