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
void insert_bef(int x,int val){
	struct node *p,*ptr,*preptr;
	p=getnode();
	p->info=x;
	if(start==NULL)
		start=p;
	else{
		ptr=start;
		while(ptr->info!=val && ptr!=NULL){
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=p;
		p->next=ptr;
	}
}//end of insert_before function
void insert_after(int x,int val){
	struct node *p,*ptr,*preptr;
	p=getnode();
	p->info=x;
	if(start==NULL)
		start=p;
	else{
		ptr=start;
		preptr=ptr;
		while(ptr->info!=val){
				preptr=ptr;
				ptr=ptr->next;
		}//End of while loop
		preptr->next=p;
		p->next=ptr;
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
		preptr->next=NULL;
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
	else if (start->next==NULL)
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
	struct node*ptr,*nptr,*nnptr;
	if(start==NULL){
		printf("The list is empty");
		return;
	}//End of if function
	else if (start->next==NULL)
		printf("The list has only one element please try other delete functions ! \n ");
	else{
		ptr=start;
		while(ptr->info!=val){
				ptr=ptr->next;
				nptr=ptr->next;
				nnptr=nptr->next;	
			}
		ptr->next=nnptr;
		printf("Deleted node is: %d",nptr->info);
		free(nptr);
	}	
}//End of delete_after function

void count(){
	struct node *ptr;
	int count=1;
	//As we didnt count the first node
	if(start==NULL){
			printf("The link list is empty ");
			return;
		}
	else{
		ptr=start;
		while(ptr->next!=NULL){
				ptr=ptr->next;
				count+=1;
			}
	}//End of else condition
	printf("The number of nodes in the list is: %d",count);
}//End of count function

void sort(){
	struct node *ptr,*nptr;
	int temp;
	if(start==NULL)
		printf("List is empty");
	else if(start->next==NULL)
		printf("The list has only one element");
	else{
		ptr=start;
		nptr=ptr->next;
		while(ptr->next!=NULL){
			while(nptr!=NULL){
				if(ptr->info>nptr->info){
					temp=ptr->info;
					ptr->info=nptr->info;
					nptr->info=temp;
				}//End of if condition
			nptr=nptr->next;
			}//End of inner while
		ptr=ptr->next;
		nptr=ptr->next;
		}//End of outer while
	}//End of else condition
	printf("We have sorted your link list! The sorted link list is: \n");
	display();
}//End of sort function
int main(){
	struct node *p,*previous,*ptr;
	int choice,x,val;
	p=(struct node *)malloc(sizeof(struct node));
	while(1){
		printf("\n Enter your choice: \n 1.Insert first \n 2.display \n 3.Add element at last \n 4.Insert a node after \n 5.Insert a node before \n 6. delete a specific node  \n 7. delete the first node \n 8. delete the last node \n 9. delete before a specific node \n 10. delete after a specific node\n 11. sort \n 12. count number of nodes \n 13.Exit\n");
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
					//sort
					sort();
					break;
			case 12: 
					//Count number of nodes
					count();
					break;
			case 13: 
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
 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 1

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 2

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 3

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 4

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 5

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes  Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 1

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 2

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 3

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 4

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
1
Enter the value: 5

 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
2
The list is: 
5 	4 	3 	2 	1 	
 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
11
We have sorted your link list! The sorted link list is: 
1 	2 	3 	4 	5 	

 13.Exit
2
The list is: 
5 	4 	3 	2 	1 	
 Enter your choice: 
 1.Insert first 
 2.display 
 3.Add element at last 
 4.Insert a node after 
 5.Insert a node before 
 6. delete a specific node  
 7. delete the first node 
 8. delete the last node 
 9. delete before a specific node 
 10. delete after a specific node
 11. sort 
 12. count number of nodes 
 13.Exit
11
We have sorted your link list! The sorted link list is: 
1 	2 	3 	4 	5 	

*/
