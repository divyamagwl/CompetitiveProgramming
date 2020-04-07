#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 2147483646
#define INT_MIN -2147483646

int fill(int n)
{
    int power_of_2 = 1;
    while(n>0)
    {
        n = n/2;
        power_of_2 *= 2;        
    }
    return power_of_2;
}

void PrintSegmentTree(int segment_tree[], int n)
{
    for(int i= 0; i<2*n-1 ; i++)
    {
        printf("%d ",segment_tree[i]);
    }
    printf("\n");
}

void BuildMaxSegmentTree(int array[], int segment_tree[], int n)
{
    for(int i = 0; i<n; i++)
    {
        segment_tree[n-1+i] = i;
    }
    for(int i = n-2; i > -1; i--)
    {
        if(array[segment_tree[2*i+1]] < array[segment_tree[2*i+2]])
        {
            segment_tree[i] = segment_tree[2*i+2];
        }
        else
        {
            segment_tree[i] = segment_tree[2*i+1];
        }
    }
}

void BuildMinSegmentTree(int array[], int segment_tree[], int n)
{
    for(int i = 0; i<n; i++)
    {
        segment_tree[n-1+i] = i;
    }
    for(int i = n-2; i > -1; i--)
    {
        if(array[segment_tree[2*i+1]] > array[segment_tree[2*i+2]])
        {
            segment_tree[i] = segment_tree[2*i+2];
        }
        else
        {
            segment_tree[i] = segment_tree[2*i+1];
        }
    }
}

void Build(int maxArray[], int minArray[], int maxST[], int minST[], int n)
{
    BuildMaxSegmentTree(maxArray, maxST, n);
    BuildMinSegmentTree(minArray, minST, n);
}

void UpdateMaxSegmentTree(int array[], int segment_tree[], int n, int index, int value)
{
    array[index] = value;
    int parent = ((n-1+index)-1)/2;

    while( parent > 0 )
    {
        if(array[segment_tree[2*parent+1]] < array[segment_tree[2*parent+2]])
        {
            segment_tree[parent] = segment_tree[2*parent+2];
        }
        else{
            segment_tree[parent] = segment_tree[2*parent+1];
        }
        parent = (parent-1)/2;
    }

    segment_tree[0] = array[segment_tree[1]] < array[segment_tree[2]] ? segment_tree[2] : segment_tree[1];
}

void UpdateMinSegmentTree(int array[], int segment_tree[], int n, int index, int value)
{
    array[index] = value;
    int parent = ((n-1+index)-1)/2;

    while( parent > 0 )
    {
        if(array[segment_tree[2*parent+1]] > array[segment_tree[2*parent+2]])
        {
            segment_tree[parent] = segment_tree[2*parent+2];
        }
        else{
            segment_tree[parent] = segment_tree[2*parent+1];
        }
        parent = (parent-1)/2;
    }

    segment_tree[0] = array[segment_tree[1]] > array[segment_tree[2]] ? segment_tree[2] : segment_tree[1];
}

void Update(int maxArray[], int minArray[], int maxST[], int minST[], int n, int index, int value)
{
    if(maxArray[index] == value || minArray[index] == value)
        return;
    
    UpdateMaxSegmentTree(maxArray, maxST, n, index, value);
    UpdateMinSegmentTree(minArray, minST, n, index, value);
}

int RangeMaxQuery(int array[], int segment_tree[], int n, int i, int j, int start, int end, int root)
{    
    if (start > j || end < i)
    {
        return n;
    }
    else if (start >= i && end <= j)
    {
        return segment_tree[root];
    }

    int mid = (start+end)/2;

    int left = RangeMaxQuery(array,segment_tree,n,i,j,start,mid,2*root+1);
    int right = RangeMaxQuery(array,segment_tree,n,i,j,mid+1,end,2*root+2);

    if(array[left] > array[right])
        return left;
    else
        return right;
}


int RangeMinQuery(int array[], int segment_tree[], int n, int i, int j, int start, int end, int root)
{    
    if (start > j || end < i)
    {
        return n;
    }
    else if (start >= i && end <= j)
    {
        return segment_tree[root];
    }

    int mid = (start+end)/2;

    int left = RangeMinQuery(array,segment_tree,n,i,j,start,mid,2*root+1);
    int right = RangeMinQuery(array,segment_tree,n,i,j,mid+1,end,2*root+2);

    if(array[left] < array[right])
        return left;
    else
        return right;
}

int Query(int maxArray[], int minArray[], int maxST[], int minST[], int n, int X, int c)
{
    int start = 1, end = n-X;
    int mid, flag;
    while(start < end)
    {
        mid = (start + end)/2;
        int max = RangeMaxQuery(maxArray, maxST, n, X, X+mid-1, 0, n-1, 0);
        int min = RangeMinQuery(minArray, minST, n, X, X+mid-1, 0, n-1, 0);
        if(minArray[X]-c <= minArray[min] && maxArray[max] <= maxArray[X]+c)
        {
            start = mid + 1;
            flag = 1;
        }
        else
        {
            end = mid;
            flag = 0;
        }
    }
    if(flag)
        return mid;
    else
        return mid-1;
}

int minimumZQuery(int maxArray[], int minArray[], int maxST[], int minST[], int n, int X, int len)
{
    int max = RangeMaxQuery(maxArray, maxST, n, X, X+len-1, 0, n-1, 0);
    int min = RangeMinQuery(minArray, minST, n, X, X+len-1, 0, n-1, 0);
    int Z1 = maxArray[max] - maxArray[X];
    int Z2 = minArray[X] - minArray[min];
    return Z1 > Z2 ? Z1 : Z2;
}

int main()
{
    int num, q; 
    scanf("%d %d",&num, &q);
    int* max_array, *min_array, *max_ST, *min_ST;

    int n = fill(num);

    max_array = (int*)calloc(n,sizeof(int));
    min_array = (int*)calloc(n,sizeof(int));
    max_ST = (int*)calloc(2*n,sizeof(int));
    min_ST = (int*)calloc(2*n,sizeof(int));

    for(int i = 0; i<num; i++)
    {
        int number;
        scanf("%d",&number);
        max_array[i] = number;
        min_array[i] = number;
    }

    for(int i = num; i<n; i++)
    {
        max_array[i] = INT_MAX;
        min_array[i] = INT_MIN; 
    }
    max_array[n] = INT_MIN;
    min_array[n] = INT_MAX;

    Build(max_array, min_array, max_ST, min_ST, n);

    for(int i = 0; i<q; i++)
    {
        char query[2];
        int X; int value; //Indexing starts from 1
        scanf("%s %d %d",query, &X, &value);
        if(strcmp("U",query) == 0)
        {
            Update(max_array, min_array, max_ST, min_ST, n, X-1, value);
        }
        else if(strcmp("Q",query) == 0)
        {
            if(value < 0)
            {
                printf("-1 -1\n");
            }
            else
            {
                int len = Query(max_array, min_array, max_ST, min_ST, n, X-1, value);
                int minZ = minimumZQuery(max_array, min_array, max_ST, min_ST, n, X-1, len);
                printf("%d %d\n",len, minZ);
            }
        }
    }
 
    return 0;
}