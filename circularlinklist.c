/*
Samyak Gaur(8604)
Batch B
A program to implement circular link list 
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
	if(start == NULL){
		start=newnode;
        start->next=newnode;
    }
	else{
		p=start;
		while(p->next!=start)
			p=p->next;
		newnode->next=start;
		p->next=newnode;
		start=newnode;
	}//End of else	
}//End of insert_first function
void display(){
	struct node *p;
	if(start==NULL)
		printf("The linked list is empty");
	else{
		p=start;
		while(p->next!=start){
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
		while(p->next!=start)
			p=p->next;
		p->next=newnode;
		newnode->next=start;
	}//End of else 
}//End of addlast function
void insert_bef(int x,int val){
	struct node *p,*ptr,*preptr;
	p=getnode();
	p->info=x;
	if(start==NULL)
		start=p;
	else{
		ptr=start;
		preptr=start;
		while(ptr->info!=val && ptr->next!=start){
			preptr=ptr;
			ptr=ptr->next;
		}
		p->next=ptr;
		preptr->next=p;
	}
}//end of insert_before function
void insert_after(int x,int val){
	struct node *p,*ptr;
	p=getnode();
	p->info=x;
	if(start==NULL)
		start=p;
	else{
		ptr=start;
		while(ptr->info!=val && ptr->next!=start){
				ptr=ptr->next;
		}//End of while loop
		p->next=ptr->next;
		ptr->next=p;
	}
	
}//End of insert_after function
void delete_specific(int val){
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
		while(ptr->info!=val && ptr->next!=start){
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

void delete_beg(){
	struct node*ptr;
	if(start==NULL){
		printf("The list is empty");
		return;
	}//End of if function
	else if (start->next==NULL){
		free(start);
		start=NULL;
	}//if there's only one node in the list
	else{
	ptr=start;
	start=ptr->next;
	printf("Deleted node is: %d",ptr->info);
	free(ptr);
	}	
}//End of delete_beg function

void delete_last(){
	struct node*ptr,*preptr;
	if(start==NULL){
		printf("The list is empty");
		return;
	}//End of if function
	else if (start->next==NULL){
		free(start);
		start=NULL;
	}//if there's only one node in the list
	else{
		ptr=start;
		while(ptr->next!=NULL){
				preptr=ptr;
				ptr=ptr->next;
			}
		preptr->next=start;
		printf("Deleted node is: %d",ptr->info);
		free(ptr);
	}	
}//End of delete_last function


void delete_bef(int val){
	struct node*ptr,*preptr,*prepre;
	if(start==NULL){
		printf("The list is empty");
		return;
	}//End of if function
	else if (start->next==start)
		printf("The list has only one element please try other delete functions ! \n ");
	else{
		ptr=start;
		while(ptr->info!=val){
				prepre=preptr;
				preptr=ptr;
				ptr=ptr->next;
			}
		prepre->next=ptr;
		printf("Deleted node is: %d",preptr->info);
		free(preptr);
	}	
}//End of delete_bef function

void delete_after(int val){
	struct node*ptr,*preptr;
	if(start==NULL){
		printf("The list is empty");
		return;
	}//End of if function
	else if (start->next==start)
		printf("The list has only one element please try other delete functions ! \n ");
	else{
		ptr=start;
		preptr=start;
		while(ptr->info!=val){
				preptr=ptr;
				ptr=ptr->next;
			}
			if(ptr==start)
				start=preptr->next;
		preptr->next= ptr->next;
		printf("Deleted node is: %d",ptr->info);
		free(ptr);
	}	
}//End of delete_after function

int main(){
	struct node *p,*previous,*ptr;
	int choice,x,val;
	p=(struct node *)malloc(sizeof(struct node));
	while(1){
		printf("\n Enter your choice: \n 1.Insert first \n 2.display \n 3.Add element at last \n 4.Insert a node after \n 5.Insert a node before \n 6. delete a specific node  \n 7. delete the first node \n 8. delete the last node \n 9. delete before a specific node \n 10. delete after a specific node\n 11.Exit\n");
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
					printf("Enter the value after which node should be added: ");
					scanf("%d",&val);
					printf("Enter the value: ");
					scanf("%d",&x);
					insert_after(x,val);
					break;
			case 5: 
					printf("Enter the value before which node should be added: ");
					scanf("%d",&val);
					printf("Enter the value: ");
					scanf("%d",&x);
					insert_bef(x,val);
					break;
			case 6: 
					printf("Enter the value to delete: ");
					scanf("%d",&x);
					delete_specific(x);
					break;
			case 7: 
					//delete beginning
					delete_beg();
					break; 
			case 8: 
					//delete end
					delete_last();
					break; 
			case 9: 
					//delete before specific
					printf("Enter the value before which node should be deleted: ");
					scanf("%d",&val);
					delete_bef(val);
					break; 
			case 10: 
					//delete after specific
					printf("Enter the value after which node should be deleted: ");
					scanf("%d",&val);
					delete_after(val);
					break;  
			case 11: 
					exit(0);
			default:
					printf("Please enter a valid choice:");
					break;
			}//End of switch case
	}//End of while loop
	return 0;
}//End of main function

/*
*/