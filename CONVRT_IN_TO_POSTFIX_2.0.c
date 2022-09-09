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
    int i,j=0,result;
    char ch;
    struct Stack s;
    s.tos=-1;
    for(i=0;*(infix+i)!='\0';i++)
    {
        ch=*(infix+i);
        if(isoperand(ch))
        {
            *(postfix+j)=ch;
            j++;
            printf("%c inserted in postfix\n",ch);
        }
        else{
            while(isempty(s)==0)
            {
                result=precedence(ch,s.arr[s.tos]);
                if(result==1)
                    break;
                postfix[j]=pop(&s);
                j++;
            }
            push(&s,ch);
        }
    }
    while(isempty(s)==0)
    {
        *(postfix+j)=pop(&s);
        j++;
    }
    postfix[j]='\0';
}
int isoperand(char ch)
{
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || (ch>=48 && ch<=57))
    {
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char push_ch,char pop_ch)
{
    if(pop_ch=='$')
        return 0;
    else if(push_ch=='$')
        return 1;
    else if(pop_ch=='*' || pop_ch=='/' || pop_ch=='%')
        return 0;
    else if(push_ch=='*' || push_ch=='/' || push_ch=='%')
        return 1;
    else if(pop_ch=='+' || pop_ch=='-')
        return 0;
    else
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
