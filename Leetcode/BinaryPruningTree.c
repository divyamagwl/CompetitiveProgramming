// Q - https://leetcode.com/problems/binary-tree-pruning/

struct TreeNode* pruneTree(struct TreeNode* root){
    
    if(root != NULL)
    {
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && root->left == NULL && root->right == NULL)
            root = NULL;
    } 
    return root;
}

