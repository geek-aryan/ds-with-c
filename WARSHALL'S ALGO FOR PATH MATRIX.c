#include<stdio.h>
void warshall(int [][4], int[][4]);

int main()
{
    int adj[4][4],path[4][4];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Is there a path from vertex V[%d] to V[%d] ? (Yes-1,No-0):",i+1,j+1);
            scanf("%d",&adj[i][j]);
        }
    }
    warshall(adj,path);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d",path[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void warshall(int adj[][4],int path[][4])
{
    int k,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            path[i][j]=adj[i][j];
        }
    }
    for(k=0;k<4;k++)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                path[i][j]=path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }
}
