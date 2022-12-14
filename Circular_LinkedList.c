#include<stdio.h>
#include<stdlib.h>
struct cnode
{
    int data;
    struct cnode* next;
};
void append(struct cnode**,int);
void display(struct cnode*);
//int count_node(struct node*);
//int search_node(struct node*,int);
void del_first(struct cnode**);
void del_last(struct cnode**);
void del_any(struct cnode**,int);
void insert(struct cnode**,int);
int main()
{
    struct cnode* start=NULL;
    int x;
    for(int i=1;i<=5;i++)
    {
        printf("Enter a data to insert in list: ");
        scanf("%d",&x);
        insert(&start,x);
    }
    display(start);
    for(int i=1;i<=5;i++)
    {
        printf("Enter a data to delete in list: ");
        scanf("%d",&x);
        del_any(&start,x);
        display(start);
    }

//    del_first(&start);
//    printf("After deleting first node into the list: \n");
//    display(start);
//
//    del_last(&start);
//    printf("After deleting first node into the list: \n");
//    display(start);
    return 0;
}
void append(struct cnode** ps,int x)
{
    struct cnode *p,*temp;
    p=(struct cnode*)malloc(sizeof(struct cnode));
    p->data=x;
    if(*ps==NULL)
    {
        p->next=p;
        *ps=p;
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        temp=temp->next;
    }
    p->next=*ps;
    temp->next=p;
}
void display(struct cnode* p)
{
    struct cnode* temp;
    if(p==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    temp=p;
    do
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=p);
}
//int count_node(struct node* p)
//{
//    int c=0;
//    while(p!=NULL)
//    {
//        p=p->next;
//        c++;
//    }
//    return c;
//}
//int search_node(struct node* p,int x)
//{
//    int pos=0;
//    if(p==NULL)
//        return 0;
//    while(p!=NULL)
//    {
//        pos++;
//        if(p->data==x)
//            return pos;
//        p=p->next;
//    }
//    return -1;
//}
void del_first(struct cnode **ps)
{
    struct cnode* temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next==*ps)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        temp=temp->next;
    }
    *ps=(*ps)->next;
    free(temp->next);
    temp->next=*ps;
}
void del_last(struct cnode **ps)
{
    struct cnode *prev,*temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next==*ps) //(*ps) bracket is required because of precedence of oprtr
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=*ps;
}
void del_any(struct cnode **ps,int x)
{
    struct cnode *temp,*prev;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=*ps;
    if((*ps)->data==x)
    {
        if((*ps)->next==*ps)
        {
            free(*ps);
            *ps=NULL;
            printf("Node is deleted\n");
            return;
        }
        while(temp->next==*ps)
        {
            temp=temp->next;
        }
        *ps=(*ps)->next;
        free(temp->next);
        temp->next=*ps;
        printf("Node is deleted\n");
        return;
    }
    while(temp->next!=NULL && temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp->data==x)
    {
        prev->next=temp->next;
        free(temp);
        printf("Node is deleted\n");
    }
    else{
        printf("Node not found!\n");
    }
}
void insert(struct cnode** ps,int x)
{
    struct cnode *p,*temp,*prev;
    p=(struct cnode*)malloc(sizeof(struct cnode));
    p->data=x;
    if(*ps==NULL)
    {
        p->next=p;
        *ps=p;
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
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
        p->next=temp->next;
        *ps=p;
        temp->next=p;
        return;
    }
    p->next=*ps;
    temp->next=p;
}
