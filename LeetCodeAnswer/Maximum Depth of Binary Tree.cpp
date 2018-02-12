#include "TreeNode.h"
#include <queue>
using namespace std;
namespace Solution
{
    int maxDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int size = 0;
        int depth = 0;
        TreeNode *nodePtr;
        while(!nodes.empty())
        {
            ++depth;
            size = nodes.size();
            while(size--)
            {
                nodePtr = nodes.front();
                nodes.pop();
                if (nodePtr->left)
                    nodes.push(nodePtr->left);
                if (nodePtr->right)
                    nodes.push(nodePtr->right);
            }
        }
        return depth;
    }
}
