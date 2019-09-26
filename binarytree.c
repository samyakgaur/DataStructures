/*
Samyak Gaur(8604)
Batch B
A program to implement binary tree 
*/
#include<stdio.h>
#include<stdlib.h>
#define max 25
struct node {
	int info;
	struct node *left , *right;
	};//End of structure
struct node *root = NULL;

struct node *getnode(){
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	return p;
}//End of getnode function
void insert(int x){ 
    struct node *newnode,*t,*parent=NULL;
    newnode=getnode();
    newnode->info= x;
    newnode->right= NULL;
    newnode->left= NULL;
    if(root == NULL)
        root=newnode;
    else{
        parent=root;
        t=root;
        while(t!=NULL){
            if(newnode->info < t->info){
                parent=t;
                t=t->left;
            }//if condition to insert to the left
            else if(newnode->info > t->info){
                parent=t;
                t=t->right;
            }//if condition to insert to the right
            else 
                printf("node exists");
        }//End of while loop 
        if(newnode->info < parent->info)
            parent->left=newnode;
        else 
            parent->right=newnode;
    }//End of else case
}//End of insert_first function
void inorder(struct node *t){
	if(t!=NULL){
        inorder(t->left);
        printf("%d ",t->info);
        inorder(t->right);
    }//End of if condition
}//End of inorder function
void preorder(struct node *t){
	if(t!=NULL){
        printf("%d ",t->info);
        preorder(t->left);
        preorder(t->right);
    }//End of if condition
}//End of preorder function
void postorder(struct node *t){
	if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d ",t->info);
    }//End of if condition
}//End of postorder function

void delete(struct node *p ,int val){
    int flag=0;
    struct node *t,*parent,*r;
    t=p;
    parent=NULL;
    while(t!=NULL){
        if(val < t->info){
            parent=t;
            t=t->left;
        }//end of if case going to the left
        else if(val > t->info){
            parent=t;
            t=t->right;
        }//end of if case going to the right
        else{
            flag=1;
            break;
        }//End of  else case
    }//end of while loop
    if(flag==1){
        if(t->left==NULL && t->right==NULL){
            if(parent->left==t)
                parent->left=NULL;
            else if (parent->right==t)
                parent->right=NULL;
            free(t);
        }//End of leaf node condition
        else if(t->left!=NULL && t->right==NULL){
            if(parent->left==t)
                parent->left=t->left;
            else
                parent->right=t->left;
        }//end if theres a element in left
        else if(t->left==NULL && t->right!=NULL){
            if(parent->left==t)
                parent->left=t->right;
            else 
                parent->right=t->right;
        }//End if the node has a right element
        else{
            r=t->left;
            while(r->right!=NULL){
                r=r->right;
                t->info=r->info;
                delete(t->left,r->info);
            }//End of while condition
        }//end of else condition if it has both children
    }//End of if flag condition 
}//End of delete function
int main(){
	struct node *p,*previous,*ptr;
	int choice,x,val;
	p=(struct node *)malloc(sizeof(struct node));
	while(1){
		printf("\n Enter your choice: \n 1.Insert \n 2.Inorder display \n 3.Preorder display \n 4.Postorder display \n 5.Delete \n 6.Exit \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					printf("Enter the value: ");
					scanf("%d",&x);
					insert(x);
					break;
			case 2: 
					inorder(root);
					break;
            case 3: 
					preorder(root);
					break;
            case 4: 
					postorder(root);
					break;
            case 5: 
					//delete before specific
					printf("Enter the value to be deleted: ");
					scanf("%d",&val);
					delete(root,val);
					break;  
			case 6: 
					exit(0);
			default:
					printf("Please enter a valid choice:");
					break;
			}//End of switch case
	}//End of while loop
	return 0;
}//End of main function

/*
Output of the following code is:
(base) Samyaks-MacBook-Air:DataStructures samyakgaur$ gcc binarytree.c 
(base) Samyaks-MacBook-Air:DataStructures samyakgaur$ ./a.out 

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 25

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 15

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 12

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 18

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 16

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 38

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 32

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 36

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 45

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
1
Enter the value: 48

 Enter your choice: 
 1.Insert 
 2.Inorder display 
 3.Preorder display 
 4.Postorder display 
 5.Delete 
 6.Exit 
2
12 15 16 18 25 32 36 38 45 48
*/