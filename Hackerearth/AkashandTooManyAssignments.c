// Q - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/akash-and-too-many-assignments/
     
#include<stdio.h>
#include<stdlib.h>

int RangeSumQuery(int segment_tree[], int n, int leftLimit, int rightLimit, int start, int end, int root)
{
    if (start > rightLimit || end < leftLimit)
    {
        return 0;
    }
    else if (start >= leftLimit && end <= rightLimit)
    {
        return segment_tree[root];
    }

    int mid = (start+end)/2;

    int left = RangeSumQuery(segment_tree,n,leftLimit,rightLimit,start,mid,2*root+1);
    int right = RangeSumQuery(segment_tree,n,leftLimit,rightLimit,mid+1,end,2*root+2);

    return left + right;
}

int LexiKSmallestChar(int* segment_tree[], int n, int left_limit, int right_limit, int K)
{
    for(int i = 0; i<26; i++)
    {
        if( K <= 0 )
        {
            return -1;
        } 
        int sum = RangeSumQuery(segment_tree[i], n, left_limit, right_limit, 0, n-1, 0);
        if(sum >= K)
        {
            return i;
        }
        K -= sum;
    }
    return -1;
}
    
void UpdateSegmentTree(char* string, int* segment_tree[], int n, int index, char value)
{
    char character = string[index];

    if(character == value)
    {
        return;
    }
   
    string[index] = value;

    segment_tree[character-'a'][n-1+index] = 0;
    segment_tree[value-'a'][n-1+index] = 1;

    int parent = ((n-1+index)-1)/2;
    
    while( parent > 0)
    {
        segment_tree[character-'a'][parent] -= 1;
        segment_tree[value-'a'][parent] += 1;
        parent = (parent-1)/2;
    }
    
    segment_tree[character-'a'][0] -= 1;
    segment_tree[value-'a'][0] += 1;

}
    
void BuildSegmentTree(int* segment_tree[], int n)
{
    for(int j = 0; j<26; j++)
    {
        for(int i = n-2; i > -1; i--)
        {
            segment_tree[j][i] = segment_tree[j][2*i+1] + segment_tree[j][2*i+2];
        }
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
    int num; int q;
    scanf("%d %d",&num, &q);
    
    int n = fill0s(num);
    
    char* string = calloc(n,sizeof(char));
    scanf("%s",string); 

    int *segment_tree[26]; 

    for (int i = 0; i < 26; i++)
    { 
        segment_tree[i] = (int *)calloc(2*n , sizeof(int)); 
    }

    for(int i = 0; i<num; i++)
    {
        int character = string[i] - 'a'; 
        segment_tree[character][n-1+i] = 1;
    }

    BuildSegmentTree(segment_tree, n);

    for(int i = 0; i<q; i++)
    {
        int query;
        scanf("%d",&query);
        if(query == 0)
        {
            int index; char character; //Indexing starts from 1
            scanf("%d %c",&index, &character);
            UpdateSegmentTree(string, segment_tree, n, index-1, character);
        }
        else if(query == 1)
        {
            int left_limit, right_limit, K;
            scanf("%d %d %d",&left_limit, &right_limit, &K); //Indexing starts from 1
            int ans = LexiKSmallestChar(segment_tree, n, left_limit-1, right_limit-1, K);

            if(ans != -1)
                printf("%c\n",ans+'a');
            else
                printf("Out of range\n");
        }
    }

    return 0;
}
