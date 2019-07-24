/*
Samyak Gaur (8604)
Batch B

Program to implement struct stack
*/
#define max 10
#include<stdio.h>
#include<stdlib.h>
struct stack{
	int a[max];
	int top;
 };
void push(struct stack *p,int x);
int display(struct stack *p);
void pop(struct stack *p);
void isFull(struct stack *p);
void isEmpty(struct stack *p);
void peep(struct stack *p);
void main(){
 	int i , choice=0,n;
 	struct stack s;
 	s.top=-1;
 	while(1){
	printf("Enter your choice from the following options \n 1.Push \n 2.Pop \n 3.Display \n 4.isFull\n 5.isEmpty 		\n 6.Peep \n 7.Exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{	
		case 1:
				printf("enter the value to push into the stack: ");
				scanf("%d",&n);
				push(&s,n);
				break;
		case 2:
				pop(&s);
				break;
		case 3:
				display(&s);
				break;
		case 4:
				isFull(&s);
				break;
		case 5:
				isEmpty(&s);
				break;
		case 6:
				peep(&s);
				break;
		case 7:
				printf("Thank you! See you again ! \n");
				exit(0);
				break;
	}					//end of switch case
	}					//End of while loop
}						//End of main
void push(struct stack *p,int x)
{
	if(p->top==max)
		printf("Stack overflow");
	else{
		p->top++;
		p->a[p->top]=x;
	}//end of else condition
}//End of push function  

int display(struct stack *p){
	int i;
	for(i=0;i<=p->top;i++)
		printf("The elements in the array are: %d\n",p->a[i]);	
}//End of display function 		
void pop(struct stack *p)
{
	if(p->top==-1){
		printf("Stack underflow");
		printf("The popped value is: -1 \n");
	}//End of if condition
	else{
		printf("The popped value is: %d \n",p->a[p->top]);
		--p->top;
	}//end of else condition
}//End of pop function  
void isFull(struct stack *p)
{
	if(p->top==max)
		printf("Stack is Full");
	else{
		printf("The stack is not full and has %d elements in it \n",(p->top+1));
		--p->top;
	}//end of else condition
}//End of isFull function  
void isEmpty(struct stack *p)
{
	if(p->top==-1)
		printf("Stack is Empty");
	else{
		printf("The stack is not Empty and has %d elements in it \n",(p->top+1));
		--p->top;
	}//end of else condition
}//End of isEmpty function  
void peep(struct stack *p)
{
	if(p->top==-1)
		printf("Stack Underflow");
	else{
		printf("The top most element: %d \n",(p->a[p->top]));
		--p->top;
	}//end of else condition
}//End of peep function  

/*
universe@dell3:~/Desktop$ ./a.out
Enter your choice from the following options 
 1.Push 
 2.Pop 
 3.Display 
 4.isFull
 5.isEmpty 		
 6.Peep 
 7.Exit
1
enter the value to push into the stack: 2
Enter your choice from the following options 
 1.Push 
 2.Pop 
 3.Display 
 4.isFull
 5.isEmpty 		
 6.Peep 
 7.Exit
3
The elements in the array are: 2
Enter your choice from the following options 
 1.Push 
 2.Pop 
 3.Display 
 4.isFull
 5.isEmpty 		
 6.Peep 
 7.Exit
2
The popped value is: 2 


*/
