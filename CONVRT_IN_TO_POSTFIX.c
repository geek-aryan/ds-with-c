#include<stdio.h>
struct Stack{
    char arr[10];
    int tos;
};
void push(struct Stack*,char);
char pop(struct Stack*);
void convert(char*,char*);
int isoperand(char);
int precedence(char,char);
int isempty(struct Stack);
int main()
{
    char infix[20],postfix[20];
    printf("Enter a infix expression: ");
    scanf("%s",infix);
    printf("Infix expression is: %s\n",infix);
    convert(postfix,infix);
    printf("After conversion postfix expression is: %s",postfix);
    return 0;
}
void convert(char* postfix,char* infix)
{
    int i,j=0;
    char push_ch,pop_ch;
    struct Stack s;
    s.tos=-1;
    for(i=0;*(infix+i)!='\0';i++)
    {
        push_ch=*(infix+i);
        if(isoperand(push_ch))
        {
            *(postfix+j)=push_ch;
            j++;
            printf("%c inserted in postfix\n",push_ch);
        }
        else{
            again:
            if(s.tos==-1)
            {
                push(&s,push_ch);
            }
            else
            {
                pop_ch=s.arr[s.tos];
                printf("prec of push %c and pop %c is: %d\n",push_ch,pop_ch,precedence(push_ch,pop_ch));

                if(precedence(push_ch,pop_ch)==1)
                {
                    push(&s,push_ch);
                }
                else
                {
                    pop_ch=pop(&s);
                    *(postfix+j)=pop_ch;
                    j++;
                    printf("%c inserted in postfix\n",pop_ch);
                    goto again;
                }
            }
        }
    }
    while(s.tos!=-1)
    {
        push_ch=pop(&s);
        *(postfix+j)=push_ch;
        j++;
    }
}
int isoperand(char ch)
{
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
    {
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char push_ch,char pop_ch)
{
    if(push_ch=='+' || push_ch=='-')
    {
        if(pop_ch=='+' || pop_ch=='-' || pop_ch=='*' || pop_ch=='/' || pop_ch=='$')
        {
            return 0;
        }
    }
    else if(push_ch=='*' || push_ch=='/')
    {
        if(pop_ch=='*' || pop_ch=='/' || pop_ch=='$')
        {
            return 0;
        }
    }
    else if(pop_ch=='$' && push_ch=='$')
        return 0;
    return 1;
}
int isempty(struct Stack s)
{
    if(s.tos==-1)
        return 1;
    return 0;
}


void push(struct Stack* s,char x)
{
    if(s->tos==9)
    {
        printf("Stack is overflow\n");
        return;
    }
    s->tos++;
    s->arr[s->tos]=x;
    printf("%c element is pushed in stack\n",x);
}
char pop(struct Stack* s)
{
    if(s->tos==-1)
    {
        printf("Stack is underflow\n");
        return '\0';
    }
    char x=s->arr[s->tos];
    s->tos--;
    printf("%c element is popped\n",x);
    return x;
}
