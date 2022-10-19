#include<stdio.h>
#include<stdlib.h>
struct tbt{
    struct tbt* left;
    int data;
    struct tbt* right;
    int thread;
};
void append(struct tbt**,int);
void inorder(struct tbt*);
int main()
{
    struct tbt *root=NULL;
    append(&root,10);
    append(&root,20);
    append(&root,5);
    append(&root,2);
    append(&root,12);
    append(&root,30);
    append(&root,8);
    append(&root,15);

    printf("inorder:\n");
    inorder(root);
    return 0;
}
void append(struct tbt** pr,int x)
{
    struct tbt* p,*temp,*prev;
    p=(struct tbt*)malloc(sizeof(struct tbt));
    p->data=x;
    p->left=NULL;
    p->thread=0;
    if(*pr==NULL)
    {
        p->right=NULL;
        *pr=p;
        printf("append:%d\n",x);
        return;
    }
    temp=*pr;
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->thread==1)
            break;
        if(temp->data>x)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(prev->data>x)
    {
        prev->left=p;
        p->right=prev;
        p->thread=1;
        printf("append:%d\n",x);
    }
    else{
        p->right=prev->right;
        if(p->right!=NULL)
            p->thread=1;
        prev->right=p;
        prev->thread=0;
        printf("append:%d\n",x);
    }
}
void inorder(struct tbt* p)
{
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    left:
    while(p->left!=NULL)
    {
        p=p->left;
    }
    while(p->right!=NULL)
    {
            printf("%d\n",p->data);
            if(p->thread==0)
            {
                p=p->right;
                goto left;
            }
            p=p->right;
    }
    printf("%d\n",p->data);
}
