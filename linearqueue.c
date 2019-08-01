/*
Samyak Gaur(8604)
Batch B

A program to implement queue  
*/

#include<stdio.h>
#include<stdlib.h>
#define max 10
struct queue{
	int a[10];
	int front,rear;
};


void enque(struct queue *p, int x){
	if(p->rear == max-1)
		printf("Queue overflow");
	else if(p->front==-1 && p->rear==-1){
		p->front++;
		p->rear++;
		p->a[p->rear]=x;		
	}//End of else if condition
	else{
		p->rear++;
		p->a[p->rear]=x;
	}//End of else condition 
}//End of enque function

int deque(struct queue *p){
	int x;
	if(p->front==-1 && p->rear==-1){
		printf("Queue Underflow");
		return 0;
	}
	else if(p->front==p->rear){
		x=p->a[p->front];
		p->front=-1;
		p->rear=-1;
		return x;
	}//End of if else function
	else{
		x=p->a[p->front];
		p->front++;
		return x;
	}//End of else condition
}//End of deque function
void display(struct queue *p){
	int i;
	if(p->front==-1 && p->rear==-1)
		printf("Stack is empty");
	else{
		for(i=p->front;i<=p->rear;i++)
			printf("%d ",p->a[i]);
	}//End of else condition 
}//End of display function
void main(){
 	int i , choice=0,n;
 	struct queue q;
 	q.front=-1;
 	q.rear=-1;
 	while(1){
	printf("Enter your choice from the following options to perform on queue \n 1.Enque \n 2.Deque \n 3.Display \n 4.Exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{	
		case 1:
				printf("enter the value to push into the queue: ");
				scanf("%d",&n);
				enque(&q,n);
				break;
		case 2:
				n=deque(&q);
				printf("The element is: %d",n);
				break;
		case 3:
				display(&q);
				printf("\n");
				break;
		case 4:
				printf("Thank you! See you again ! \n");
				exit(0);
				break;
	}					//end of switch case
	}					//End of while loop
}						//End of main

/*
Output of the following code is:
Enter your choice from the following options to perform on queue 
 1.Enque 
 2.Deque 
 3.Display 
 4.Exit
1
enter the value to push into the queue: 1
Enter your choice from the following options to perform on queue 
 1.Enque 
 2.Deque 
 3.Display 
 4.Exit
1
enter the value to push into the queue: 2
Enter your choice from the following options to perform on queue 
 1.Enque 
 2.Deque 
 3.Display 
 4.Exit
1
enter the value to push into the queue: 3
Enter your choice from the following options to perform on queue 
 1.Enque 
 2.Deque 
 3.Display 
 4.Exit
2
The element is: 1Enter your choice from the following options to perform on queue 
 1.Enque 
 2.Deque 
 3.Display 
 4.Exit
3
2 3 


*/
