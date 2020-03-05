// Q - https://leetcode.com/problems/container-with-most-water/

int Min(int a, int b) { return (a < b) ? a : b; }

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize -1 ;
    int max_area = 0;
    while(left < right)
    {
        if(Min(height[left] , height[right])*(right-left) > max_area)
            max_area = Min(height[left] , height[right])*(right-left);
        
        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return max_area;
}


