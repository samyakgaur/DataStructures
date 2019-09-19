
/*
 Samyak Gaur
 Roll Number 8604
 Batch B
 Program to implement priority queue using link list
*/
#define max 5
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int info,priority;
	struct node *next;
}; //end of structure
struct node *start=NULL;
void insert(int x,int n){
	struct node *p,*prev;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	prev=(struct node *)malloc(sizeof(struct node));
	newnode->info=x;
	newnode->priority=n;
	newnode->next=NULL;
	if(start==NULL)
		start=newnode;
	else if(newnode->priority>start->priority){
		prev=start;
		p=start;
		while(p!=NULL && p->priority<=newnode->priority){
			prev=p;
			p=p->next;
		}
	newnode->next=p;
	prev->next=newnode;
	}//End of else if 
	else{
	newnode->next=start;
	start=newnode;
	}
} //end of insert
void delete(){
	struct node *p;
	if(start==NULL)
	printf("List is Empty\n");
	else{
		p=start;
		start=start->next;
		printf("The deleted node is %d\n",p->info);
		free(p);
	}
} //end of delete
void display(){
	struct node *p;
	if(start==NULL)
	printf("List is Empty\n");
else{
	p=start;
	printf("The elements in the link list are\n");
	printf("PRIORITY  INFO\n");
	while(p!=NULL){
		printf("    %d       %d\n",p->priority,p->info);
		p=p->next;
	}//end of while
	}//end of else
} //end of display
void main(){
	struct node *p;
	int x,choice,n;
	while(1)
	{
		printf("Enter your choice:\n1.insert as per priority\n2.delete \n3.display\n4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter value to be entered into queue :");
					scanf("%d",&x);
					printf("Enter priority of the node :");
					scanf("%d",&n);
					insert(x,n);
					break;
			case 2: delete();
					break;	
			case 3: display();
					break;
			case 4: printf("Thank you\n");
					exit(0);

			default: printf("Invalid input\n");
		}//end of switch
	} //end of while
}
/*
universe@dell3:~/Desktop/8604$ cc priorityqueue.c
universe@dell3:~/Desktop/8604$ ./a.out
Enter the operation you want to perform
1.INSERT NODE AS PER PRIORITY
2.DELETE NODE
3.DISPLAY
4.EXIT
1

 enter value of node you want to store: 12

 enter the priority of the node : 23
Enter the operation you want to perform
1.INSERT NODE AS PER PRIORITY
2.DELETE NODE
3.DISPLAY
4.EXIT
1 

 enter value of node you want to store: 1

 enter the priority of the node : 1
Enter the operation you want to perform
1.INSERT NODE AS PER PRIORITY
2.DELETE NODE
3.DISPLAY
4.EXIT
1

 enter value of node you want to store: 123

 enter the priority of the node : 233
Segmentation fault (core dumped)
universe@dell3:~/Desktop/8604$ clear
[3;J
universe@dell3:~/Desktop/8604$ cc priorityqueue.c
universe@dell3:~/Desktop/8604$ ./a.out
Enter your choice:
1.insert as per priority
2.delete 
3.display
4.exit
1
Enter value to be entered into queue :12
Enter priority of the node :12
Enter your choice:
1.insert as per priority
2.delete 
3.display
4.exit
1
Enter value to be entered into queue :23
Enter priority of the node :233
Enter your choice:
1.insert as per priority
2.delete 
3.display
4.exit
1
Enter value to be entered into queue :1
Enter priority of the node :1
Enter your choice:
1.insert as per priority
2.delete 
3.display
4.exit
2
The deleted node is 1
Enter your choice:
1.insert as per priority
2.delete 
3.display
4.exit
1
Enter value to be entered into queue :1
Enter priority of the node :1
Enter your choice:
1.insert as per priority
2.delete 
3.display
4.exit
3
The elements in the link list are
PRIORITY  INFO
    1       1
    12       12
    233       23
Enter your choice:
1.insert as per priority
2.delete 
3.display
4.exit

*/
