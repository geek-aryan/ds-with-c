#include<stdio.h>
#include<stdlib.h>
struct bst
{
    struct bst * left;
    int data;
    struct bst * right;
};
struct stack
{
    struct bst * arr[5];
    int tos;
};
void append(struct bst **,int);
void push(struct stack*,struct bst*);
struct bst* pop(struct stack*);
void preorder(struct bst*);
int main()
{
    struct bst* root=NULL;
    append(&root,10);
    append(&root,20);
    append(&root,15);
    append(&root,8);
    append(&root,5);

    preorder(root);
}
void append(struct bst** pr,int x)
{
    struct bst *p,*temp,*prev;
    p=(struct bst*)malloc(sizeof(struct bst));
    if(p==NULL)
    {
        printf("Insufficiant memory\n");
        return;
    }
    p->data=x;
    p->right=p->left=NULL;
    if(*pr==NULL)
    {
        *pr=p;
        return;
    }
    temp=*pr;
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->data>x)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(prev->data<x)
        prev->right=p;
    else
        prev->left=p;
}
void push(struct stack* p, struct bst* x)
{
    if(p->tos==4)
    {
        printf("Stack overflow\n");
        return;
    }
    p->tos++;
    p->arr[p->tos]=x;
}
struct bst* pop(struct stack* p)
{
    if(p->tos==-1)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    return p->arr[p->tos--];
};
void preorder(struct bst* p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("Tree is empty!!\n");
        return;
    }
    s.tos=-1;
    push(&s,p);
    while(s.tos!=-1)
    {
        p=pop(&s);
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            if(p->right!=NULL)
                push(&s,p->right);
            p=p->left;
        }
    }
}
