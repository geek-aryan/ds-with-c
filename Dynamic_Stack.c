#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
void push(struct stack **,int);
struct stack* pop(struct stack**);
int main()
{
    struct stack *tos=NULL;
    struct stack *p;
    int choice=0,x;
    while(choice!=3)
    {
        printf("Please select an option:\n1.PUSH\n2.POP\n3.QUIT\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter an element to push in dynamic stack: ");
            scanf("%d",&x);
            push(&tos,x);
            printf("%d is pushed\n",x);
            break;
        case 2:

            p=pop(&tos);
            if(p!=NULL)
            {
                printf("Popped data is: %d\n",p->data);
                free(p);
            }
            break;
        case 3:
            printf("Thank you for using the application.\n!!!See You Again!!!");
            break;
        default:
            printf("You entered wrong choice please try again!!!\n");
        }
    }
}
void push(struct stack **ptos,int x)
{
    struct stack *p;
    p=(struct stack*)malloc(sizeof(struct stack));
    if(p==NULL)
    {
        printf("stack is overflow\n");
        return;
    }
    p->data=x;
    p->next=*ptos;
    *ptos=p;
}
struct stack * pop(struct stack **ptos)
{
    if(*ptos==NULL)
    {
        printf("Stack is underflow\n");
        return NULL;
    }
    struct stack *p;
    p=*ptos;
    *ptos=(*ptos)->next;
    return p;
};
