// Q - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/k-th-bit-faae0e0d/description/

#include<stdio.h>
#include<stdlib.h>

int KthOne(int segment_tree[], int n, int K, int start, int end, int root)
{    
    if (K > segment_tree[root])
    {
        return -1;
    }
    else if (K == segment_tree[root] && start == end)
    {
        return end;
    }

    int mid = (start+end)/2;

    int left = KthOne(segment_tree,n,K,start,mid,2*root+1);
    
    if(left == -1)
    {        
        int right = KthOne(segment_tree,n,K-segment_tree[2*root+1],mid+1,end,2*root+2);
        return right;
    }
    else
    {
        return left;
    }
}

void UpdateSegmentTree(int segment_tree[], int n, int index)
{
    if(segment_tree[n-1+index] == 0)
        return;

    segment_tree[n-1+index] = 0;
    int parent = ((n-1+index)-1)/2;

    while( parent > 0)
    {
        segment_tree[parent] -= 1;
        parent = (parent-1)/2;
    }

    segment_tree[0] -= 1;
}

void BuildSegmentTree(int array[], int segment_tree[], int n)
{
    for(int i = 0; i<n; i++)
    {
        segment_tree[n-1+i] = array[i];
    }
    for(int i = n-2; i > -1; i--)
    {
        segment_tree[i] = segment_tree[2*i+1] + segment_tree[2*i+2];
    }
}

int fill0s(int n)
{
    int power = 1;
    while(n>0)
    {
        n = n/2;
        power *= 2;        
    }
    return power;
}

int main()
{
    int num;
    scanf("%d",&num);

    int n = fill0s(num);

    int* array = calloc(n,sizeof(int));

    for(int i= 0; i<num ; i++)
    {
        array[i] = 1;
    }
    for(int i= num; i<n; i++)
    {
        array[i] = 0;
    }

    int* segment_tree = calloc(4*n,sizeof(int));;
    BuildSegmentTree(array,segment_tree, n);

    int num_queries;
    scanf("%d",&num_queries);

     for(int i = 0; i<num_queries; i++)
    {
        int query;
        scanf("%d",&query);
        if(query == 0)
        {
            int index; //Indexing starts from 1
            scanf("%d",&index);
            UpdateSegmentTree(segment_tree,n,index-1);
        }
        else if(query == 1)
        {
            int K;
            scanf("%d",&K);
            int index = KthOne(segment_tree,n,K,0,n-1,0);
            if(index != -1)
                printf("%d\n",index+1); //Indexing starts from 1
            else
                printf("-1\n");
        }
    }


    return 0;
}