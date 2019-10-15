/* Samyak Gaur
 SE COMPUTERS
 BATCH B 8604
 */
#include<stdio.h>
#include<stdlib.h>
#define n 10
#define max 50
struct queue{
 int a[max];
 int front,rear;
};
struct stack{
 int b[max];
 int top;
};
void enqueue(struct queue *,int x);
int dequeue(struct queue *);
void push(struct stack *,int x);
int pop(struct stack *);
int Empty(struct queue *);
int isempty(struct stack *);
void BFS(int [n][n],int);
void DFS(int [n][n],int);
int main()
{
 int i,j,e,s,d;
 int G[n][n]={0};
 printf("Enter number of edges\n");
 scanf("%d",&e);
 for(i=0;i<e;i++)
 {
  printf("Enter source and destination\n");
  scanf("%d",&s);
  scanf("%d",&d);
  G[s][d]=1;
  G[d][s]=1;
 }
 printf("Enter source node for BFS\n");
 scanf("%d",&s);
 BFS(G,s);
 printf("\n");
 printf("Enter source node for DFS\n");
 scanf("%d",&s);
 DFS(G,s);
 printf("\n");
}

void BFS(int g[n][n],int source)
{
 int visited[n]={0};
 int v,i;
 struct queue q;
 q.front=-1;
 q.rear=-1;
 visited[source]=1;
 enqueue(&q,source);
 while(!Empty(&q))
 {
  v=dequeue(&q);
  printf("%d\t",v);
  for(i=0;i<n;i++)
  {
   if((g[v][i]==1)&&(visited[i]==0))
   {
    visited[i]=1;
    enqueue(&q,i);
   }
  }
 }
}

void DFS(int g[n][n],int source)
{
 int visited[n]={0};
 int v,i;
 struct stack s;
 s.top=-1;
 visited[source]=1;
 push(&s,source);
 while(!isempty(&s))
 {
  v=pop(&s);
  printf("%d\t",v);
  for(i=0;i<n;i++)
  {
   if((g[v][i]==1)&&(visited[i]==0))
   {
    visited[i]=1;
    push(&s,i);
   }
  }
 }
}
  
void push(struct stack *p,int m)
  {
   if(p->top==max-1)
   {
    return;
   }
   else
   {
    p->top++;
    p->b[p->top]=m;
   }
  }
int pop(struct stack * p)
{
   int m;
   if(p->top==-1)
   {
    return -1;
   }
   else
   {
    m=p->b[p->top];
    p->top--;
    return m;
   }
}
  
int isempty(struct stack *p)
{
 if(p->top==-1)
   {
   return 1;
   }
   else
   {
   return 0;
   }
}

void enqueue(struct queue *r,int m)
{
 if(r->front==-1&&r->rear==-1)
 {
  r->front=0;
  r->rear=0;
  r->a[r->rear]=m;
 }
 else if(r->rear==max-1)
 {
  return;
 }
 else
 {
  r->rear++;
  r->a[r->rear]=m;
 }
}
int dequeue(struct queue *r)
{
 int m;
 if(r->front==-1&&r->rear==-1)
 {
  return 0;
 }
 else if(r->front==r->rear)
 {
  m=r->a[r->front];
  r->front=-1;
  r->rear=-1;
  return m;
 }
 else
 {
  m=r->a[r->front];
  r->front++;
  return m;
 }
}

int Empty(struct queue * r)
{
 if((r->front==-1)&&(r->rear==-1))
 {
  return 1;
 }
 else
 {
  return 0;
 }
}


/*
universe@dell12:~/Desktop/DS$ cc graph.c
universe@dell12:~/Desktop/DS$ ./a.out
Enter number of edges
5
Enter source and destination
1
7
Enter source and destination
0
1
Enter source and destination
2
0
Enter source and destination
3
7
Enter source and destination
4
3
Enter source node for BFS
0
0	1	2	7	3	4	
Enter source node for DFS
4
4	3	7	1	0	2	
universe@dell12:~/Desktop/DS$ 
*/
