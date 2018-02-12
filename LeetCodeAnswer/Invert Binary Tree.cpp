#include "TreeNode.h"
namespace Solution
{
    TreeNode* invertTree(TreeNode *root)
    {
        if (!root) 
            return root;
        invertTree_iter(root);
        return root;
    }
    
    void invertTree_iter(TreeNode* root) 
    {
        if (!root->left && !root->right)
            return;
        TreeNode *nodeptr = root->left;
        root->left = root->right;
        root->right = nodeptr;
        if (root->left)
            invertTree_iter(root->left);
        if (root->right)
            invertTree_iter(root->right);
    }
}
