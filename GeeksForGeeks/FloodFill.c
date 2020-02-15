#include<stdio.h>
#define MAX 1000

//Question - https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0

void floodFill(int array[][MAX], int m, int n, int x, int y, int k, int check)
{
    if(array[x][y] == check)
    {
        array[x][y] = k;
    }
    else
        return;

    if(x > 0)
    {
        floodFill(array, m, n, x-1, y, k, check);
    }
    if(x < m-1)
    {
        floodFill(array, m, n, x+1, y, k, check);
    }
    if(y > 0)
    {
        floodFill(array, m, n, x, y-1, k, check);
    }
    if(y < n-1)
    {
        floodFill(array, m, n, x, y+1, k, check);
    }
    
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    
    for(int test =0; test<T; test++)
    {
        int m, n, x, y, k;
        int array[MAX][MAX];
        scanf("%d %d",&m, &n);

        for(int i =0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                scanf("%d ",&array[i][j]);
            }
        }

        scanf("%d %d %d",&x, &y, &k);

        int check = array[x][y];

        floodFill(array,m,n,x,y,k,check);

        printf("\nFinal Matrix-\n");
        for(int i =0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}