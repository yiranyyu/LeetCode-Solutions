#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;
namespace Solution
{
    static void AddToVector(TreeNode *node, vector<TreeNode*> &vec)
    {
        vec.push_back(node);
    }
    static void inOrderTravel(TreeNode *root, vector<TreeNode*> &vec, void(*callback)(TreeNode*, vector<TreeNode*>&))
    {
        if (!root)
            return;
        else
        {
            if (root->left)
                inOrderTravel(root->left, vec, callback);
            callback(root, vec);
            if (root->right)
                inOrderTravel(root->right, vec, callback);
        }
    }
    TreeNode* convertBST(TreeNode* root)
    {
        if (!root || (!root->left && !root->right)) // if empty or single
            return root;

        stack<TreeNode*> nodes;
        nodes.push(root);
        vector<TreeNode*> sorted_nodes;
        TreeNode *nodeptr = root;
        bool fromLeft = true;

        inOrderTravel(root, sorted_nodes, AddToVector);
        
        int size = sorted_nodes.size();
        int tail = size - 1;
        int amount = sorted_nodes[tail]->val;

        while (--tail >= 0)
        {
            int old = amount;
            amount += sorted_nodes[tail]->val;
            sorted_nodes[tail]->val += old;
        }
        return root;
    }
}
