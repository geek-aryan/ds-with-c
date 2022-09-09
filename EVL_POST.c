#include<stdio.h>
struct Stack
{
    float arr[10];
    int tos;
};
void push(struct Stack*,float);
float pop(struct Stack*);
int isoprnd(char);
float calculate(float,float,char);
float solve(char*);
int main()
{
    char arr[20];
    printf("Enter a valid postfix expression: ");
    scanf("%s",arr);
    float result=solve(arr);
    printf("Postfix expression is %s\nResult is %f",arr,result);
    return 0;
}
void push(struct Stack* s,float x)
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
float pop(struct Stack* s)
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
