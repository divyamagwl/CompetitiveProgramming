#include<stdio.h>
#define Prime 1000000007 

//Question - https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0

int main()
{
    int T;
    scanf("%d",&T);

    for(int test = 0; test<T; test++)
    {
        int n;
        scanf("%d",&n);
        //Fibonacci Sequence
        int result = 0;
        int a = 1, b = 1;
        for(int i=1; i<=n; i++)
        {
            result = (a+b)%Prime;
            a = b;
            b = result;
        }
        printf("%d\n",result);
    }
    return 0;
}