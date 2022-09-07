#include<stdio.h>
#include<math.h>
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
    char arr[20];//56*2/4-7+
    printf("Enter a valid postfix expression: ");
    scanf("%s",arr);
    float result=solve(arr);
    printf("Postfix expression is %s\nResult is %f",arr,result);
    return 0;
}
float solve(char* postfix)
{
    int i;
    struct Stack s;
    char ch;
    float op1,op2,result;
    s.tos=-1;
    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isoprnd(ch)==1)
        {
            push(&s,ch-'0');
        }
        else{
            op2=pop(&s);
            op1=pop(&s);
            result=calculate(op1,op2,ch);
            push(&s,result);
        }
    }
    result=pop(&s);
    return result;
}
int isoprnd(char ch)
{
    if(ch>=48 && ch<=57)
    {
        return 1;
    }
    else{
        return 0;
    }
}
float calculate(float op1,float op2,char ch)
{
    switch(ch)
    {
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    case '%':
        return fmod(op1,op2);
    case '$':
        return pow(op1,op2);
    default:
        return 0;
    }
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
    printf("%f element is pushed in stack\n",x);
}
float pop(struct Stack* s)
{
    if(s->tos==-1)
    {
        printf("Stack is underflow\n");
        return -1;
    }
    float x=s->arr[s->tos];
    s->tos--;
    printf("%f element is popped\n",x);
    return x;
}
