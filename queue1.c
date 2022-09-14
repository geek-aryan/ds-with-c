#include<stdio.h>
struct Queue
{
    int arr[5];
    int front;
    int rear;
};
void insert(struct Queue*,int);
int del(struct Queue*);
int main()
{
    struct Queue q;
    q.front=0;
    q.rear=-1;
    int i,x;
    for(i=1;i<=6;i++)
    {
        printf("Enter elements to insert into the queue: ");
        scanf("%d",&x);
        insert(&q,x);
    }
    for(i=1;i<=6;i++)
    {
        x=del(&q);
        if(x!=-1)
            printf("Deleted element is: %d\n",x);
    }
}
void insert(struct Queue* q,int x)
{
    if(q->rear==4)
    {
        printf("Queue is Overflow\n");
        return;
    }
    q->rear++;
    q->arr[q->rear]=x;
    printf("%d inserted\n",x);
}
int del(struct Queue* q)
{
    if(q->front>q->rear)
    {
        printf("Queue is Underflow\n");
        return -1;
    }
    int x=q->arr[q->front++];
    return x;
}
