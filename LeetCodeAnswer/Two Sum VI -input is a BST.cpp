#include "TreeNode.h"
#include <queue>
using namespace std;
namespace Solution
{
    static bool cmp(const TreeNode* a, const TreeNode* b)
    {
        return a->val < b->val;
    }
    bool findTarget(TreeNode* root, int k) 
    {
        if (!root || (!root->left && !root->right)) // if empty or only one node
            return false;
        
        vector<TreeNode*> sorted_nodes;
        queue<TreeNode*> nodes; // to access the tree in levels order
        nodes.push(root);
        int cnt = 0;
        int size = 0;
        TreeNode *nodeptr;
        while(!nodes.empty())
        {
            size = nodes.size();
            for (cnt = 0; cnt < size; ++cnt)
            {
                nodeptr = nodes.front();
                sorted_nodes.push_back(nodeptr);
                nodes.pop();
                if (nodeptr->left)
                    nodes.push(nodeptr->left);
                if (nodeptr->right)
                    nodes.push(nodeptr->right);
            }
        }
        auto begin = sorted_nodes.begin();
        auto tail = begin + (sorted_nodes.size() - 1);
        sort(begin, sorted_nodes.end(), Solution::cmp);
        if (sorted_nodes.back()->val * 2 <= k || (*begin)->val * 2 >= k)
            return false;
        int sum = 0;
        while (begin < tail)
        {
            sum = (*begin)->val + (*tail)->val;
            if (sum < k)
                ++begin;
            else if (sum > k)
                --tail;
            else
                return true;
        }
        return false;
    }
}
