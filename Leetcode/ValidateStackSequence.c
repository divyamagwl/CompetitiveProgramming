#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100000

// Q- https://leetcode.com/problems/validate-stack-sequences/

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int top = -1;
    int stack[MAX];
    int current_push = 0, current_pop = 0;

    while(current_push <= pushedSize && current_pop < poppedSize)
    {
        if (top < 0)
        {
            stack[++top] = pushed[current_push++];
        }

        if (stack[top] == popped[current_pop])
        {
            top--;
            current_pop++;
        }
        else if (current_push < pushedSize && stack[top] != popped[current_pop])
        {
            stack[++top] = pushed[current_push++];
        }
        else
        {
            break;
        }
    }

    if(current_push == pushedSize && current_pop == poppedSize)
        return true;
    else
        return false;
}

int main()
{
    int n, pushed_size, popped_size;
    scanf("%d",&n);
    pushed_size = n;
    popped_size = n;

    int pushed[MAX], popped[MAX];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&pushed[i]);
    }
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&popped[i]);
    }

    if(validateStackSequences(pushed, pushed_size, popped, popped_size))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}