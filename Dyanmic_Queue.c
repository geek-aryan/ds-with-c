#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue * next;
};
void insert(struct queue**,struct queue**,int);
int del(struct queue**,struct queue**);
int main()
{
    struct queue *front=NULL,*rear=NULL;
    insert(&front,&rear,10);
    printf("10 inserted\n");
    insert(&front,&rear,20);
    printf("20 inserted\n");
    insert(&front,&rear,30);
    printf("30 inserted\n");
    insert(&front,&rear,40);
    printf("40 inserted\n");
    insert(&front,&rear,50);
    printf("50 inserted\n");

    printf("deleted %d\n",del(&front,&rear));
    printf("deleted %d\n",del(&front,&rear));
    printf("deleted %d\n",del(&front,&rear));
    printf("deleted %d\n",del(&front,&rear));
    printf("deleted %d\n",del(&front,&rear));
    printf("deleted %d\n",del(&front,&rear));
}
void insert(struct queue** pf,struct queue** pr,int x)
{
    struct queue *p;
    p=(struct queue*)malloc(sizeof(struct queue));
    if(p==NULL)
    {
        printf("Queue is overflow\n");
        return;
    }
    p->data=x;
    p->next=NULL;
    if(*pr==NULL)
    {
        *pf=p;
        *pr=p;
        return;
    }
    (*pr)->next=p;
    *pr=p;

}
int del(struct queue** pf,struct queue** pr)
{
    if(*pf==NULL)
    {
        printf("Queue is underflow\n");
        return -1;
    }
    struct queue * temp=*pf;
    int x=(*pf)->data;
    *pf=(*pf)->next;
    free(temp);
    if(*pf==NULL)
        *pr=NULL;
    return x;
}
