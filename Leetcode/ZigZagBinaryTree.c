#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 10000
#define swap(a,b) {char (temp); temp = a; a = b; b = temp;}

// Q - https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

char* decTobin(int n)
{
    char* binary = calloc(MAX,sizeof(char));
    int index = 0;
    while (n > 0)
    {
        int remainder = n % 2;
        binary[index++] = remainder + '0';
        n = n/2; 
    }

    for(int i = 0; i<index/2; i++)
    {
        swap(binary[i] , binary[index-i-1]);
    }
    return binary;
}

int* pathInZigZagTree(int label, int* returnSize)
{
    int* path = malloc(MAX * sizeof(int));
    int* normal = malloc(MAX * sizeof(int));
    int* alter = malloc(MAX * sizeof(int));

    char* binary = malloc(MAX);
    binary = decTobin(label);
    int len = strlen(binary);

    normal[0] = 1; alter[0] = 1;

    for(int i = 1; i < len; i++)
    {
        if(binary[i] == '0')
        {
            normal[i] = 2*normal[i-1];
            alter[i] = 2*alter[i-1] + 1;
        }
        else
        {
            normal[i] = 2*normal[i-1] + 1;
            alter[i] = 2*alter[i-1];
        }  
    }

    if (len%2 == 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (i%2 == 0)
                path[i] = alter[i];
            else
                path[i] = normal[i];
        }
    }
    else
    {
        for(int i = 0; i < len; i++)
        {
            if (i%2 == 0)
                path[i] = normal[i];
            else
                path[i] = alter[i];
        }
    }
    *returnSize = len;
    return path;
}

int main()
{
    int label;
    scanf("%d",&label);
    int* path = malloc(MAX * sizeof(int));
    int* returnSize; 
    path = pathInZigZagTree(label, returnSize);

    for (int i = 0; i < *returnSize; i++)
    {
        printf("%d ",path[i]);
    }
    printf("\n");
    
    return 0;
}