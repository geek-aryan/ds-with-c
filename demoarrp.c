#include<stdio.h>
void main()
{
    int arr[10],x=0;

    for(int i=0;i<10;i++)
    {
        x++;
        arr[i]=x;
    }
    show(arr);
}
void show(int *p)
{
    for(int i=0;i<10;i++)
    {
        printf("%d\n",p[i]);
    }
}
