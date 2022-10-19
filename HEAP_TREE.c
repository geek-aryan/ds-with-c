#include<stdio.h>

void insert(int[],int,int);
void swap(int*,int*);
int del_root(int[],int);
int main()
{
    int arr[11];
    int i,x;
    for(i=1;i<10;i++)
    {
        printf("Enter a element:");
        scanf("%d",&x);
        insert(arr,i,x);
    }
    for(i=1;i<10;i++)
    {
        printf("%d\n",arr[i]);
    }
    int len=sizeof arr;
    del_root(arr,len);
    printf("After del_root:\n");
    for(i=1;i<10;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}
void insert(int arr[],int index,int x)
{
   int ptr,par;
   ptr=index;
   while(ptr>1)
   {
       par=ptr/2;
       if(arr[par]>x)
       {
           arr[ptr]=x;
           return;
       }
       arr[ptr]=arr[par];
       ptr=par;
   }
   arr[1]=x;
}
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int del_root(int arr[],int n)
{
    int x,i,j;
    x=arr[1];
    arr[1]=arr[n];
    i=1;
    j=i*2;
    n=n-1;
    while(j<n)
    {
        if(arr[j+1]>arr[j])
        {
            j=j+1;
        }
        if(arr[j]>arr[i])
        {
            swap(&arr[i],&arr[j]);
            i=j;
            j=i*2;
        }
        else{
            break;
        }
    }
    return x;
}
