#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define swap(a,b) {int (temp); temp = a; a = b; b = temp;}

// Q- https://leetcode.com/problems/last-stone-weight/

void TopDownHeapify(int heap[], int length, int parent)
{
    int right_child = 2*parent + 2;
    int left_child = 2*parent + 1;
    while(right_child < length)
    {
        int max_child;
        if(heap[left_child] < heap[right_child])
            max_child = right_child;
        else
            max_child = left_child;

        if(heap[parent] < heap[max_child])
        {
            swap(heap[parent],heap[max_child]);
            parent = max_child;
            right_child = 2*parent + 2;
            left_child = 2*parent + 1;
        } 
        else
            break;
    }

    if(left_child<length && heap[parent] < heap[left_child])
    {
        swap(heap[parent],heap[left_child]);
    }
}

void BuildHeap(int heap[], int length)
{
    for(int i =length/2; i>=0; i--)
    {
        TopDownHeapify(heap, length, i);
    }
}
 
void BottomUpHeapify(int heap[], int child)
{
    int parent = (child-1)/2;

    while(parent >= 0 && heap[parent]<heap[child])
    {
        swap(heap[child],heap[parent]);
        child = parent;
        parent = (child-1)/2;
    }
}

void DeleteMax(int heap[], int length)
{
    heap[0] = heap[--length];
    TopDownHeapify(heap, length, 0);
}

void Update(int heap[], int length, int index, int data)
{
    if(heap[index] > data)
    {
        heap[index] = data;
        TopDownHeapify(heap, length, index);
    }
    else if(heap[index] < data)
    {
        heap[index] = data;
        BottomUpHeapify(heap, index);
    }
}

void Delete(int heap[], int length, int index)
{
    Update(heap, length, index, heap[0]+1);
    DeleteMax(heap, length);
}

int LastStone(int heap[], int length)
{
    BuildHeap(heap, length);

    while(length > 1)
    {
        int parent = 0;
        int left_child = 2*parent + 1;
        int right_child = 2*parent + 2;
        int max_child;
        if(right_child < length)
        {
            if(heap[left_child] < heap[right_child])
                max_child = right_child;
            else
                max_child = left_child;
        }
        else
        {
            max_child = left_child;
        }
        int value = heap[0]-heap[max_child];
        Delete(heap, length, max_child);
        length--;

        if(value != 0)
            Update(heap, length, 0, value);
        else
        {
            Delete(heap, length, 0);
            length--;
        }        
    }

    if(length != 0)
        return heap[0];
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d\n",&n);
    int heap[MAX];

    for(int i =0; i < n; i++)
    {
        scanf("%d",&heap[i]);
    }

    int result = LastStone(heap, n);
    printf("%d\n",result);
    return 0;
}