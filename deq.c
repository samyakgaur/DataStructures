#include<stdio.h>
#include<stdlib.h>
#define max 5

struct queue
{
	int a[max];
	int front, rear;	
};

void insert_rear(struct queue *p, int x)
{
    if((p->rear+1)%max==p->front)
    {
     	printf("Queue Overflow\n");
    }
	else
    {
      	p->rear=(p->rear+1)%max;
     	p->a[p->rear]=x;
    }
}

void insert_front(struct queue *p, int x)
{
    if((p->rear+1)%max==p->front)
    {
     	printf("Queue Overflow\n");
    }
	else
    {
      	p->front=(p->front-1)%max;
     	p->a[p->front]=x;
    }
}

int delete_front(struct queue *p)
{ 
    int x;
    if(p->front==p->rear)
    {
    	printf("Queue Underflow\n");
       	return 0;	
    }
    else
    {
    	p->front=(p->front+1)%max;
		x=p->a[p->front];
        return x;
    }
}

int delete_rear(struct queue *p)
{ 
    int x;
    if(p->front==p->rear)
    {
    	printf("Queue Underflow\n");
       	return 0;	
    }
    else
    {
    	x=p->a[p->rear];
    	p->rear=(p->rear-1)%max;
        return x;
    }
}

void display(struct queue *p)
{
	int i;
	if(p->front==p->rear)
		printf("No elements to display\n");
	else
	{
		for(i=(p->front+1)%max;i<=p->rear;i++)
			{
				printf("%d\n",(p->a[i]));
			}
	}
}

int main()
{
	int x, ch, c;
	struct queue q;
	q.front = -1;
	q.rear = -1;
	printf("Enter your choice of restriction\n1. I/P restricted\n2. O/P restricted\n\n");
	scanf("%d", &c);
	if(c==1)
	{
		do
		{
			printf("***** MENU *****\n\n1. Insert element to queue\n2. Delete element from front\n3. Delete element from rear\n4. Display\n5. Exit\n\n");
			scanf("%d", &ch);
			switch(ch)
			{
				case 1:
					printf("Enter element to be inserted: ");
					scanf("%d", &x);
					insert_rear(&q, x);
					break;
				case 2:
					printf("Deleted element is %d\n", delete_front(&q));
					break;
				case 3:
					printf("Deleted element is %d\n", delete_rear(&q));
					break;
				case 4:
					display(&q);
					break;
				case 5:
					exit(1);
					break;
				default:
					printf("Invalid input\n");
					break;
			}
		}while(ch!=5);	
	}
	else if(c==2)
	{
		do
		{
			printf("***** MENU *****\n\n1. Insert element at front\n2. Insert element at rear\n3. Delete element from front\n4. Display\n5. Exit\n\n");
			scanf("%d", &ch);
			switch(ch)
			{
				case 1:
					printf("Enter element to be inserted: ");
					scanf("%d", &x);
					insert_front(&q, x);
					break;
				case 2:
					printf("Enter element to be inserted: ");
					scanf("%d", &x);
					insert_rear(&q, x);
					break;
				case 3:
					printf("Deleted element is %d\n", delete_front(&q));
					break;
				case 4:
					display(&q);
					break;
				case 5:
					exit(1);
					break;
				default:
					printf("Invalid input\n");
					break;
			}
		}while(ch!=5);			
	}
	else
		printf("Invalid input\n");
	return 0;
}
	
