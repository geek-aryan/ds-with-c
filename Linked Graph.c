#include<stdio.h>
#include<stdlib.h>

struct edge{
    char data;
    struct edge *next;
};
struct node{
    char data;
    struct node *next;
    struct edge *enext;
};

void addvertex(struct node**,char);
void insertedge(struct node*,char,char);
struct node* findevertex(struct node*,char);
//void removevertex(struct node**,char);
//void removeedge(struct node*,char,char);
void display(struct node*);

int main()
{
    struct node *start=NULL;
    char ch1,ch2;
    int choice,stop=0;
    do{
        printf("\nSelect your choice:");
        printf("\n1.Add Vertices");
        printf("\n2.Insert Edges");
        printf("\n3.Remove Vertex");
        printf("\n4.Remove Edge");
        printf("\n5.Display");
        printf("\n6.Quit/Exit");
        printf("\n6.Enter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the node name:");
            scanf(" %c",&ch1);
            addvertex(&start,ch1);
            break;
        case 2:
            printf("\nEnter source vertex and destination vertex:");
            scanf(" %c %c",&ch1,&ch2);
            insertedge(start,ch1,ch2);
            break;
        case 3:
            printf("\nEnter the node name:");
            scanf(" %c",&ch1);
//            removevertex(&start,ch1);
            break;
        case 4:
            printf("\nEnter source vertex and destination vertex:");
            scanf(" %c %c",&ch1,&ch2);
//            removeedge(start,ch1,ch2);
            break;
        case 5:
            display(start);
            break;
        case 6:
            stop=1;
            break;
        default:
            printf("\nWrong choice entered, Please try again!!!");
        }
    }while(stop==0);
    return 0;
}
void addvertex(struct node** ps,char ch)
{
    struct node *p,*temp;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=ch;
    p->next=NULL;
    p->enext=NULL;
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
struct node* findevertex(struct node* p,char ch)
{
    while(p!=NULL)
    {
        if(p->data==ch)
            return p;
        p=p->next;
    }
    return p;
}
void insertedge(struct node *p,char s,char d)
{
    struct node *q;
    struct edge *r,*t;
    q=findevertex(p,s);
    if(q==NULL)
    {
        printf("\nSource vertex missing");
        return;
    }
    if(findevertex(p,d)==NULL)
    {
        printf("\nDistance vertex missing");
        return;
    }
    r=(struct edge*)malloc(sizeof(struct edge));
    r->next=NULL;
    r->data=d;
    if(q->enext==NULL)
    {
        q->enext=r;
        return;
    }
    t=q->enext;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=r;
    printf("\nEdge added successfully!");
}
void display(struct node *p)
{
    struct edge *temp;
    if(p==NULL)
    {
        printf("\nGraph is Empty!!!");
        return;
    }
    while(p!=NULL)
    {
        printf("\nVertex %c",p->data);
        printf("\tAdjacent vertices:");
        temp=p->enext;
        while(temp!=NULL)
        {
            printf(" %c",temp->data);
            temp=temp->next;
        }
        p=p->next;
    }
}
