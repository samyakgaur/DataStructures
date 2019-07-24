/*
Samyak Gaur(8604)
Batch B

A program to implement two stacks in a single array
*/
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct stack{
	int a[max];
	int topa;
	int topb;
}; //End of structure 
void pusha(struct stack *p,int x);
void pushb(struct stack *p,int x);
void popa(struct stack *p);
void popb(struct stack *p);
void displaya(struct stack *p);
void displayb(struct stack *p);
void main(){
	struct  stack s;
	int choice,n;
	s.topa=-1;
	s.topb=max;
	while(1){
	printf("Enter your choice from the following options \n 1.Push in stack A \n 2.Push in stack B \n 3.Pop from stack A \n 4.Pop from stack B\n 5.Display stack A \n 6.Display stack B \n 7.Exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{	
		case 1:
				printf("enter the value to push into the stack A: ");
				scanf("%d",&n);
				pusha(&s,n);
				break;
		case 2:
				printf("enter the value to push into the stack B: ");
				scanf("%d",&n);
				pushb(&s,n);
				break;
		case 3:
				popa(&s);
				break;
		case 4:
				popb(&s);
				break;
		case 5:
				displaya(&s);
				break;
		case 6:
				displayb(&s);
				break;
		case 7:
				printf("Thank you! See you again ! \n");
				exit(0);
				break;
	}					//end of switch case
	}//End of while loop
}//End of main function

void pusha(struct stack *p,int x)
{
	if(p->topa==max)
		printf("Stack overflow");
	else{
		p->topa++;
		p->a[p->topa]=x;
	}//end of else condition
}//End of pusha function  

void pushb(struct stack *p,int x)
{
	if((p->topa+1)==(p->topb))
		printf("Stack overflow");
	else{
		p->topb--;
		p->a[p->topb]=x;
	}//end of else condition
}//End of pushb function  
void popa(struct stack *p)
{
	if(p->topa==-1){
		printf("Stack underflow");
		printf("The popped value is: -1 \n");
	}//End of if condition
	else{
		printf("The popped value is: %d \n",p->a[p->topa]);
		--p->topa;
	}//end of else condition
}//End of pop function  
void popb(struct stack *p)
{
	if(p->topb==max){
		printf("Stack underflow");
		printf("The popped value is: -1 \n");
	}//End of if condition
	else{
		printf("The popped value is: %d \n",p->a[p->topb]);
		++p->topb;
	}//end of else condition
}//End of pop function  
void displaya(struct stack *p){
	int i;
	for(i=0;i<=p->topa;i++)
		printf("The elements in the array are: %d\n",p->a[i]);	
}//End of display function 		
void displayb(struct stack *p){
	int i;
	for(i=max-1;i>=p->topb;i--)
		printf("The elements in the array are: %d\n",p->a[i]);	
}//End of display function 		
/*
Output of the following code is:
(base) Samyaks-MacBook-Air:~ samyakgaur$ /Users/samyakgaur/Desktop/DataStructures/a ; exit;
Enter your choice from the following options 
 1.Push in stack A 
 2.Push in stack B 
 3.Pop from stack A 
 4.Pop from stack B
 5.Display stack A 
 6.Display stack B 
 7.Exit
1
enter the value to push into the stack A: 1
Enter your choice from the following options 
 1.Push in stack A 
 2.Push in stack B 
 3.Pop from stack A 
 4.Pop from stack B
 5.Display stack A 
 6.Display stack B 
 7.Exit
2
enter the value to push into the stack B: 2
Enter your choice from the following options 
 1.Push in stack A 
 2.Push in stack B 
 3.Pop from stack A 
 4.Pop from stack B
 5.Display stack A 
 6.Display stack B 
 7.Exit
5
The elements in the array are: 1
Enter your choice from the following options 
 1.Push in stack A 
 2.Push in stack B 
 3.Pop from stack A 
 4.Pop from stack B
 5.Display stack A 
 6.Display stack B 
 7.Exit
6
The elements in the array are: 2
Enter your choice from the following options 
 1.Push in stack A 
 2.Push in stack B 
 3.Pop from stack A 
 4.Pop from stack B
 5.Display stack A 
 6.Display stack B 
 7.Exit


 */