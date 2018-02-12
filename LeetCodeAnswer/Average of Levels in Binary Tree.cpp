#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;
namespace Solution
{

    vector<double> averageOfLevels(TreeNode* root)
    {
        queue<TreeNode*> nodes;
        vector<double> averages;
        nodes.push(root);
        int size = 0;
        int cnt = 0;
        double amount = 0;
        while (!nodes.empty())
        {
            size = nodes.size();
            amount = 0;
            for (cnt = 0; cnt < size; ++cnt)
            {
                auto front = nodes.front();
                nodes.pop();
                amount += front->val;
                if (front->left != nullptr)
                {
                    nodes.push(front->left);
                }
                if (front->right != nullptr)
                {
                    nodes.push(front->right);
                }
            }
            averages.push_back(amount / size);
        }
        return averages;
    }
    
}
