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
    s.tos=-1;
    int i,x;
    for(i=1;i<=6;i++)
    {
        printf("Enter a element to push\n");
        scanf("%d",&x);
        push(&s,x);
    }
    for(i=1;i<=6;i++)
    {
        x=pop(&s);
        if(x!=-1)
            printf("Popped element is %d\n",x);
    }
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
