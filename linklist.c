/*
Samyak Gaur(8604)
Batch B

A program to implement link list 
*/
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct node {
	int info;
	struct node *next;
	};//End of structure
struct node *start = NULL;

struct node *getnode(){
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	return p;
}//End of getnode function
void insert_first(int x){
	struct node *newnode,*p;
	newnode=getnode();
	newnode->info=x;
	newnode->next=NULL;
	if(start == NULL)
		start=newnode;
		else{
			newnode->next=start;
			start=newnode;
		}//End of else	
}//End of insert_first function
void display(){
	struct node *p;
	if(start==NULL)
		printf("The linked list is empty");
	else{
		p=start;
		while(p!=NULL){
			printf("%d \t",p->info);
			p=p->next;
		}//End of while
	}//End of else 
}//End of display function
void addLast(int x){
	struct node *newnode,*p;
	newnode=getnode();
	newnode->info=x;
	newnode->next=NULL;	
	if(start==NULL)
		start=newnode;
	else{
		p=start;
		while(p->next!=NULL)
			p=p->next;
		p->next=newnode;
	}//End of else 
}//End of addlast function
void insert_before(int x,int val){
        printf("called\n");
		struct node *p,*previous,*ptr;
		p=getnode();
		if(start==NULL){
			printf("List is empty");
			start=p;
		}//End of if statements
		else{
				previous=start;
				ptr=start;
				p->info=x;
				p->next=NULL;
				//ptr=start;
				while(ptr->info!=val){
				        printf("while\n");
						previous=ptr;
						ptr=ptr->next;
				}//End of while loop
				if (ptr==NULL)
				 printf("not found\n");
				else{ 
				   printf("else\n");
					previous->next=p;
					ptr=p->next;
					printf("node added\n");	
			
			
				
			}//End of inner else
		}//End of else statement
}//end of insert_before function
void insert_after(int x){
	
}//End of insert_after function
void delete(int val){
	struct node*ptr,*previous;
	if(start==NULL){
		printf("The list is empty");
		return;
	}//End of if function
	else if(start->info==val){
	ptr=start;
	start=start->next;
	printf("Deleted node is: %d",ptr->info);
	free(ptr);
	}
	//End of else-if
	else{
		ptr=start;
		previous=start;
		while(ptr->info!=val && ptr!=NULL){
			previous=ptr;
			ptr=ptr->next;
		}//End of while loop
		if(ptr==NULL)
			printf("Node not found");
		else{
			previous->next=ptr->next;
			free(ptr);
		}//end of else
	}//End of else condition	
}//End of delete-specific function


int main(){
	struct node *p,*previous,*ptr;
	int choice,x,val;
	p=getnode();
	while(1){
		printf("\n Enter your choice: \n 1.Insert first \n 2.display \n 3.Add element at last \n 4.Insert a node after \n 5.Insert a node before \n 6. delete \n 7.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					printf("Enter the value: ");
					scanf("%d",&x);
					insert_first(x);
					break;
			case 2: 
					printf("The list is: \n");
					display();
					break;
			case 3: 
					printf("Enter the value: ");
					scanf("%d",&x);
					addLast(x);
					break;
			case 4: 
					printf("Enter the value: ");
					scanf("%d",&x);
					insert_after(x);
					break;
			case 5: 
					printf("Enter the node to after the value before : ");
					scanf("%d",&x);
					printf("Enter the value: ");
					scanf("%d",&val);
					insert_before(x,val);
					break;
			case 6: 
					printf("Enter the value to delete: ");
					scanf("%d",&x);
					delete(x);
					break;
			case 7: 
					exit(0);
			default:
					printf("Please enter a valid choice:");
					break;
			}//End of switch case
	}//End of while loop
	return 0;
}//End of main function

/*
The output for the following code is:

*/
