#include<stdio.h>
#include<stdlib.h>
struct doubly
{
    struct doubly * prev;
    int data;
    struct doubly * next;
};
void append(struct doubly**,int);
void display(struct doubly*);
void del_first(struct doubly**);
void del_last(struct doubly**);
void del_any(struct doubly**,int);

int main()
{
    struct doubly * start=NULL;
    append(&start,10);
    append(&start,20);
    append(&start,30);
    display(start);

//    del_first(&start);
//    printf("After del_first\n");
//    display(start);

//    del_last(&start);
//    printf("After del_last\n");
//    display(start);

    del_any(&start,40);
    printf("After del_any\n");
    display(start);
}
void append(struct doubly **ps,int x)
{
    struct doubly *p,*temp;
    p=(struct doubly*)malloc(sizeof(struct doubly));
    p->data=x;
    p->next=NULL;
    if(*ps==NULL)
    {
        *ps=p;
        p->prev=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    p->prev=temp;
    temp->next=p;
}
void display(struct doubly *p)
{
    if(p==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
void del_first(struct doubly **ps)
{
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next==NULL)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    *ps=(*ps)->next;
    free((*ps)->prev);
    (*ps)->prev=NULL;
}
void del_last(struct doubly **ps)
{
    struct doubly *temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next==NULL)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    (temp->prev)->next=NULL;
    free(temp);
}
void del_any(struct doubly **ps,int x)
{
    struct doubly *temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->data==x)
    {
        if((*ps)->next==NULL)
        {
            free(*ps);
            *ps=NULL;
            return;
        }
        *ps=(*ps)->next;
        free((*ps)->prev);
        (*ps)->prev=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL && temp->data!=x)
    {
        temp=temp->next;
    }
    if(temp->data==x)
    {
        (temp->prev)->next=temp->next;
        free(temp);
    }
    else{
        printf("Node not found!\n");
    }

}
