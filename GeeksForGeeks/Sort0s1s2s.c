#include<stdio.h>
#define MAX 100000

//Questiion- https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

void countSort(int array[], int n)
{
    int prefix[5] = {0};
    for(int i=0; i<n; i++)
    {
        prefix[array[i]]++; 
    }
    for(int i=1; i<3; i++)
    {
        prefix[i] = prefix[i] + prefix[i-1];
    }
    int sorted[MAX];
    for(int i=n-1; i>=0; i--)
    {
        sorted[--prefix[array[i]]] = array[i];
    }
    for(int i =0; i<n; i++)
    {
        array[i] = sorted[i];
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    
    for(int test = 0; test<T; test++)
    {
        int n; 
        scanf("%d",&n);
        int array[MAX];
        for(int i =0; i<n; i++)
        {
            scanf("%d ",&array[i]);
        }
        countSort(array,n);
        for(int i=0; i<n; i++)
        {
            printf("%d ",array[i]);
        }
        printf("\n");
    }
}
