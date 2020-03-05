// Q - https://leetcode.com/problems/distribute-coins-in-binary-tree/

int depth(struct TreeNode* root, int* moves)
{    
    if(root)
    {
        int left = depth(root->left, moves);
        int right = depth(root->right, moves);
        *moves += abs(left) + abs(right);
        return root->val + left + right - 1; 
    }
    return 0;
}

int distributeCoins(struct TreeNode* root)
{
    int total = 0;
    depth(root, &total);
    return total;
}

