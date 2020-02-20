#include<stdio.h>
#include<stdlib.h>

// Q - https://leetcode.com/problems/trapping-rain-water/submissions/

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
            Nmax[i] = max;
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
            Pmax[i] = max;
    }
}

int Min(int a, int b) { return (a < b) ? a : b; }

int trap(int* height, int heightSize)
{
    int* Nmax = calloc(heightSize, sizeof(int));
    int* Pmax = calloc(heightSize, sizeof(int));
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
    int n;
    scanf("%d",&n);
    
    int* array = malloc(n*sizeof(int));    
    for(int i =0; i<n; i++)
        scanf("%d",&array[i]);

    printf("%d\n",trap(array , n));    

    return 0;
}
