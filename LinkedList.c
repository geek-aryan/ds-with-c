#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void append(struct node**,int);
void display(struct node*);
int count_node(struct node*);
int search_node(struct node*,int);
int main()
{
    struct node* start=NULL;
    int x;
    for(int i=1;i<=10;i++)
    {
        printf("Enter a data to append in list: ");
        scanf("%d",&x);
        append(&start,x);
    }
    display(start);
    printf("\nCount of node is: %d",count_node(start));

    x=search_node(start,78);
    if(x==0)
        printf("List is empty\n");
    else if(x==-1)
        printf("\nno element found!!\n");
    else
        printf("\nserached element position is: %d\n",x);

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
        printf("%d ",p->data);
        p=p->next;
    }
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
