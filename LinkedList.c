#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void append(struct node**,int);
void display(const struct node**);
int count_node(const struct node**);
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
    display(&start);
    printf("\nCount of node is: %d",count_node(&start));
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
void display(const struct node** ps)
{
    struct node *temp=*ps;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int count_node(const struct node** ps)
{
    int c=0;
    struct node *temp=*ps;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}
