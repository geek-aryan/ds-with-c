<<<<<<< HEAD

=======
#include<stdio.h>
#include<string.h>
struct Stack
{
    char arr[10];
    int tos;
};
void push(struct Stack*,char);
char pop(struct Stack*);
int isoperand(char);
int precedence(char,char);
int isempty(struct Stack);
void convert(char*,char*);
int main()
{
    char infix[20],postfix[20];
    printf("Enter a Infix Expression: ");
    scanf("%s",infix);
    printf("Before converting Infix expression is %s\n",infix);
    convert(postfix,infix);
    printf("After converting Postfix expression is %s",postfix);
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
}
char pop(struct Stack* s)
{
    if(s->tos==-1)
    {
        printf("Stack is underflow\n");
        return '\0';
    }
    return s->arr[s->tos--];
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
void convert(char* postfix,char* infix)
{
    int i,j=0;
    char ch;
    struct Stack s;
    s.tos=-1;
    for(i=0;i<strlen(infix);i++)
    {
        ch=infix[i];
        if(isoperand(ch))
        {
            postfix[j]=ch;
            j++;
        }
        else
        {
            while(ch!=')' || isempty(s)==0)
            {
                if(ch=='(' || s.arr[s.tos]=='(')
                {
                    push(&s,ch);
                    break;
                }
                if(ch==')')
                {
                    while(s.arr[s.tos]!='(')
                    {
                            postfix[j]=pop(&s);
                            j++;
                    }
                    pop(&s);
                    break;
                }
                if(precedence(ch,s.arr[s.tos])==1)
                {
                    push(&s,ch);
                    break;
                }
                else
                {
                    postfix[j]=pop(&s);
                    j++;
                }
            }
        }

    }
    while(isempty(s)==0)
    {
        *(postfix+j)=pop(&s);
        j++;
    }
    postfix[j]='\0';
}
>>>>>>> 3e1481dc3d2f40eb452889b791578647e4ee7c64
