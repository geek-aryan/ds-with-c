#include<stdio.h>
void print10(int x){
    if(x>10)
        return;
    printf("%d\n",x);
    x++;
    print10(x);
}
int main()
{
    print10(1);
    return 0;
}
