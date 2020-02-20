#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

// Q - https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

void NextMax(int array[], int n, int Nmax[])
{
    int max = -1;
    for(int i = n-1; i>=0; i--)
    {
        if(array[i] > max)
        {
            Nmax[i] = -1;
            max = array[i];
        }    
        else
        {
            Nmax[i] = max;
        }
    }
}

void PrevMax(int array[], int n, int Pmax[])
{
    int max = -1;
    for(int i = 0; i<n; i++)
    {
        if(array[i] > max)
        {
            Pmax[i] = -1;
            max = array[i];
        }    
        else
        {
            Pmax[i] = max;
        }
    }
}

int Min(int a, int b) { return (a < b) ? a : b; }

int trap(int* height, int heightSize)
{
    int Nmax[MAX];
    int Pmax[MAX];
    NextMax(height, heightSize, Nmax);
    PrevMax(height, heightSize, Pmax);

    int water = 0;
    for(int i =0; i<heightSize; i++)
    {
        int min = Min(Nmax[i] , Pmax[i]);
        if(min > 0)
        {
            water += min - height[i]; 
        }
    }
    return water;
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int cases = 0; cases<T; cases++)
    {
        int n;
        scanf("%d",&n);
        
        int array[MAX];    
        for(int i =0; i<n; i++)
            scanf("%d",&array[i]);
    
        printf("%d\n",trap(array , n));    
    }
    return 0;
}
