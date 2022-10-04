#include<stdio.h>
#include<stdlib.h>
struct bst
{
    struct bst * left;
    int data;
    struct bst * right;
    int flag;
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
void inorder(struct bst*);
void postorder(struct bst*);
void check_bst(struct bst*);
void del_node(struct bst**,int);
int search_node(struct bst*,int,struct bst**,struct bst**);
int main()
{
    struct bst* root=NULL;
    int x;
    append(&root,10);
    append(&root,15);
    append(&root,5);
    append(&root,20);
    append(&root,8);
    append(&root,2);
    append(&root,12);

    printf("Preorder:\n");
    preorder(root);

    printf("Inorder:\n");
    inorder(root);

    printf("Postorder:\n");
    postorder(root);

    printf("Checking BST:\n");
    check_bst(root);

    printf("enter a data to delete:");
    scanf("%d",&x);
    del_node(&root,x);
    printf("Deleted %d node\n",x);

    printf("Inorder:\n");
    inorder(root);

    printf("Checking BST:\n");
    check_bst(root);
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
void inorder(struct bst *p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    s.tos=-1;
    while(p!=NULL)
    {
        push(&s,p);
        p=p->left;

        while(p==NULL && s.tos!=-1)
        {
            p=pop(&s);
            printf("%d\n",p->data);
            p=p->right;
        }
    }
}
void postorder(struct bst* p)
{
    struct stack s;
    s.tos=-1;
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    while(p!=NULL)
    {
        p->flag=1;
        push(&s,p);
        if(p->right!=NULL)
        {
            (p->right)->flag=-1;
            push(&s,p->right);
        }
        p=p->left;
        if(p==NULL)
        {
            p=pop(&s);

            while(p!=NULL && p->flag==1)
            {
                printf("%d \n",p->data);
                p=pop(&s);
            }
        }

    }
}
void check_bst(struct bst* p)
{
    struct stack s;
    int prev=0;
    int checked=1;
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    s.tos=-1;
    while(p!=NULL)
    {
        push(&s,p);
        p=p->left;

        while(p==NULL && s.tos!=-1)
        {
            p=pop(&s);
            if(prev > p->data)
            {
                checked=0;
            }
//            printf("%d\n",p->data);
            prev=p->data;
            p=p->right;
        }
    }
    if(checked==0)
        printf("this is not binary search tree\n");
    else
        printf("this is binary search tree\n");
}
int search_node(struct bst *p,int x,struct bst **pc,struct bst **ppar)
{
    struct bst* prev=NULL;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            *ppar=prev;
            *pc=p;
            return 1;
        }
        if(p->data > x)
        {
            prev=p;
            p=p->left;
        }
        else
        {
            prev=p;
            p=p->right;
        }
    }
    return 0;
}
void del_node(struct bst** pr,int x)
{
    struct bst* pc,*ppar;
    if(*pr==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    if(search_node(*pr,x,&pc,&ppar)==1)
    {
        if(pc->left==NULL && pc->right==NULL)
        {
            if((*pr)->data==x)
            {
                free(*pr);
                *pr=NULL;
                return;
            }
            if(ppar->data<x)
                ppar->right=NULL;
            else
                ppar->left=NULL;
            free(pc);
            return;
        }
        if(pc->left==NULL || pc->right==NULL)
        {
            if((*pr)->data==x)
            {
                if(pc->right==NULL)
                    *pr=pc->left;
                else
                    *pr=pc->right;
            }
            else if(ppar->data>x)
            {
                if(pc->right==NULL)
                    ppar->left=pc->left;
                else
                    ppar->left=pc->right;
            }
            else{
                if(pc->right==NULL)
                    ppar->right=pc->left;
                else
                    ppar->right=pc->right;
            }
            free(pc);
            return;
        }
        struct bst *ino_succ;
        if(pc->left!=NULL && pc->right!=NULL)
        {
            if((*pr)->data==x)
            {
                if((pc->right)->left==NULL)
                {
                    *pr=pc->right;
                    (pc->right)->left=pc->left;
                    free(pc);
                    return;
                }
            }
            else if(ppar->data<x)
            {
                if((pc->right)->left==NULL)
                {
                    ppar->right=pc->right;
                    (pc->right)->left=pc->left;
                    free(pc);
                    return;
                }
            }
            else{
                if((pc->right)->left==NULL)
                {
                    ppar->left=pc->right;
                    (pc->right)->left=pc->left;
                    free(pc);
                    return;
                }

            }
            ino_succ=(pc->right)->left;
            while(ino_succ->left!=NULL)
            {
                ino_succ=ino_succ->left;
            }
            pc->right->left=ino_succ->right;
            pc->data=ino_succ->data;
            free(ino_succ);
            return;
        }
    }
    else
        printf("Node not Found!!\n");
}
