#include<stdio.h>

//Question - https://practice.geeksforgeeks.org/problems/number-of-paths/0

int NumberofPaths(int m, int n, int x, int y)
{
    int count = 0;
    if(x == m && y == n)
    {
        return 1;
    }
    if(x < m)
        count += NumberofPaths(m,n,x+1,y);
    if(y < n)
        count += NumberofPaths(m,n,x,y+1);

    return count;
}

int main()
{
    int T;
    scanf("%d",&T);

    for(int test=0; test<T; test++)
    {
        int m, n;
        scanf("%d %d",&m,&n);
        int paths = NumberofPaths(m-1,n-1,0,0);
        printf("Number of Paths : %d\n\n",paths);
    }
    return 0;
}