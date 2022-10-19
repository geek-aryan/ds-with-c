#include<stdio.h>

struct stack
{
    int arr[10];
    int tos;
};

void push(struct stack *,int);
int pop(struct stack*);
void dsf(int[][4],int);

int main()
{
    int arr[4][4];
    int i,j,v;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Is there a path from vertex[%d] to vertex[%d] (y-1,n-0)?",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter source vertex:");
    scanf("%d",&v);
    dsf(arr,v);
    return 0;
}
void push(struct stack* s,int x)
{
    if(s->tos==9)
    {
        printf("Stack is overflow\n");
        return;
    }
    s->tos++;
    s->arr[s->tos]=x;

}
int pop(struct stack* s)
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
void dsf(int arr[4][4],int v)
{
    struct stack s;
    s.tos=-1;
    int i,status[4]={0,0,0,0};
    push(&s,v);
    while(s.tos!=-1)
    {
        v=pop(&s);
        if(status[v]==0)
        {
            printf("v[%d]\n",v);
            status[v]=1;
        }
        for(i=3;i>=0;i--)
        {
            if(arr[v][i]==1 && status[i]==0)
            {
                push(&s,i);
            }
        }
    }
}
