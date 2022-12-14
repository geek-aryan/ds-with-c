#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct Stack
{
    int arr[10];
    int tos;
};
void append(struct node**,int);
void display(struct node*);
void reverse_display(struct node*);
void lreverse(struct node**);
int count_node(struct node*);
int search_node(struct node*,int);
void del_first(struct node**);
void del_last(struct node**);
void del_any(struct node**,int);
void insert(struct node**,int);
void push(struct Stack*,int);
int pop(struct Stack*);
int main()
{
    struct node* start=NULL;
    int x;
    for(int i=1;i<=5;i++)
    {
        printf("Enter a data to insert in list: ");
        scanf("%d",&x);
        insert(&start,x);
    }
    display(start);
    printf("After reversing list then list is:\n");
    lreverse(&start);
    display(start);
//    printf("Enter data to delete into the list: ");
//    scanf("%d",&x);
//    del_any(&start,x);
//    printf("After delete list is:\n");
//    display(start);
    return 0;
}
void append(struct node** ps,int x)
{
    struct node *p,*temp;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;
    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
}
void display(struct node* p)
{
    if(p==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
void reverse_display(struct node* p)
{
    if(p==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    struct Stack s;
    s.tos=-1;
    while(p!=NULL)
    {
//        printf("%d\n",p->data);
        push(&s,p->data);
        p=p->next;
    }
    while(s.tos!=-1)
    {
        printf("%d\n",pop(&s));
    }

}
void lreverse(struct node** ps)
{
    struct node *temp,*prev,*rtemp,*rprev;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next==NULL)
        return;
    temp=*ps;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        if(*ps==prev)
        {
            rtemp=prev;
            rtemp->next=NULL;
            rprev=temp;
        }
        else{
            rprev->next=rtemp;
            rprev=temp;
            rtemp=prev;
        }
    }
    temp->next=prev;
    *ps=temp;
}
int count_node(struct node* p)
{
    int c=0;
    while(p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}
int search_node(struct node* p,int x)
{
    int pos=0;
    if(p==NULL)
        return 0;
    while(p!=NULL)
    {
        pos++;
        if(p->data==x)
            return pos;
        p=p->next;
    }
    return -1;
}
void del_first(struct node **ps)
{
    struct node* temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    //if(*ps->next==NULL)
    //{
    //    free(*ps);
    //    *ps=NULL;
    //    return;
    //}         //this is optional below lines do same
    temp=*ps;
    *ps=temp->next;
    free(temp);
}
void del_last(struct node **ps)
{
    struct node *prev,*temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next==NULL) //(*ps) bracket is required because of precedence of oprtr
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;
}
void del_any(struct node **ps,int x)
{
    int result=search_node(*ps,x);
    int allnode=count_node(*ps);
    struct node *temp,*prev,*pnext=NULL;
    if(!result)
    {
        printf("List is empty\n");
        return;
    }
    if(result==-1)
    {
        printf("Data %d is not present in List\n",x);
        return;
    }
    if(result==1)
    {
        del_first(ps);
        return;
    }
    if(result==allnode)
    {
        del_last(ps);
        return;
    }
    temp=*ps;
    while(temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    pnext=temp->next;
    free(temp);
    prev->next=pnext;
}
void insert(struct node** ps,int x)
{
    struct node *p,*temp,*prev;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;
    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    temp=*ps;
    //if(temp->next==NULL)
    //
     //   if(temp->data>x)
     //   {
     //       *ps=p;
     //       (*ps)->next==temp;
     //       return;
     //   }
     //   temp->next=p;
     //   return;
    //}
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        if(prev->data<x && temp->data>x)
        {
            p->next=temp;
            prev->next=p;
            return;
        }
    }
    if(temp->data>x)
    {
        p->next=*ps;
        *ps=p;
        return;
    }
    temp->next=p;
}
void push(struct Stack* s,int x)
{
    if(s->tos==9)
    {
        printf("Stack is overflow\n");
        return;
    }
    s->tos++;
    s->arr[s->tos]=x;
//    printf("%d element is pushed in stack\n",x);
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
