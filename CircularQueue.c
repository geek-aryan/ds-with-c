#include<stdio.h>
#include<stdlib.h>
struct Cqueue
{
    int arr[5];
    int front,rear;
};
void insert(struct Cqueue*,int);
int rem(struct Cqueue*);
int main()
{
    struct Cqueue q;
    q.rear=q.front=-1;
    int choice,x;
    do{
        printf("Select your choice:\n1.Insert\n2.Delete\n3.Quit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter an element to insert:");
            scanf("%d",&x);
            insert(&q,x);
            break;
        case 2:
            x=rem(&q);
            if(x!=-1)
                printf("%d is deleted from the queue\n",x);
            break;
        case 3:
            printf("Thanks for using the app!\n");
            exit(0);
        default:
            printf("You entered wrong choice, Please try again!!\n");
        }
    }while(1);
    return 0;
}
void insert(struct Cqueue* q,int x)
{
    if((q->rear==4 && q->front==0) || (q->rear+1==q->front))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(q->rear==4)
        q->rear=0;
    else
        q->rear++;
    q->arr[q->rear]=x;
    if(q->front==-1)
        q->front=0;
    printf("%d is inserted\n",x);
}
int rem(struct Cqueue* q)
{
    if(q->front==-1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int x=q->arr[q->front];
    if(q->rear==q->front)
        q->rear=q->front=-1;
    else if(q->front==4)
        q->front=0;
    else
        q->front++;
    return x;
}
