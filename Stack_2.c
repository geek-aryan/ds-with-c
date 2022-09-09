#include<stdio.h>
struct Stack
{
    int arr[5];
    int tos;
};
void push(struct Stack*,int);
int pop(struct Stack*);
int main()
{
    struct Stack s;
    int n,ch=0;
    s.tos=-1;
    do
    {
        printf("Select your choice\n1. Push\n2. Pop\n3. Quit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter an element to push: ");
            scanf("%d",&n);
            push(&s,n);
            break;
        case 2:
            n=pop(&s);
            if(n!=-1)
                printf("Popped %d\n",n);
            break;
        case 3:
            break;
        default:
            printf("Wrong choice entered! Please try again..\n");
            break;
        }

    }while(ch!=3);
    return 0;
}
void push(struct Stack* s,int x)
{
    if(s->tos==4)
    {
        printf("Stack is overflow\n");
        return;
    }
    s->tos++;
    s->arr[s->tos]=x;
    printf("%d element is pushed in stack\n",x);
}
int pop(struct Stack* s)
{
    if(s->tos==-1)
    {
        printf("Stack is underflow\n");
        return -1;
    }
    int x=s->arr[s->tos];
    s->tos--;
    return x;
}

