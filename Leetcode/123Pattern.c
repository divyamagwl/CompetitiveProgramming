// Q - https://leetcode.com/problems/132-pattern/
// Time Complexity - O(n^2) 
// It can be done in O(n) with the help of stack.

bool find132pattern(int* nums, int numsSize){
    for(int i = 0; i<numsSize; i++)
    {
        int state = 0, previous, current, prev_prev;

        for(int j = i; j<numsSize; j++)
        {
            current = nums[j];        
            if(state == 0)
            {
                previous = current;
                prev_prev = current;
                state = 1;
            }
            if(current > previous && (state == 1 || state == 2))
            {
                previous = current;
                state = 2;
            }
            if(prev_prev < current && current < previous && state == 2)
            {
                state = 3;
                break;
            }
        }
        if(state == 3)
            return true;
    }

    return false;
}

