#include <iostream>
using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == NULL)
            return res;
        vector<int> res_temp;
        stack<TreeNode* > node1, node2;
        node1.push(pRoot);
        int depth = 1;
        while (!node1.empty() || !node2.empty())
        {
            if (depth % 2 == 1)
            {
                while (!node1.empty())
                {
                    TreeNode* p = node1.top();
                    res_temp.push_back(p->val);
                    if (p->left != NULL)
                    {
                        node2.push(p->left);
                    }
                    if (p->right != NULL)
                    {
                        node2.push(p->right);
                    }
                    node1.pop();
                }
                res.push_back(res_temp);
                res_temp.clear();
                depth++;
            }
            else 
            {
                while (!node2.empty())
                {
                    TreeNode* p = node2.top();
                    res_temp.push_back(p->val);
                    if (p->right != NULL)
                    {
                        node1.push(p->right);
                    }
                    if (p->left != NULL)
                    {
                        node1.push(p->left);
                    }
                    node2.pop();
                }
                res.push_back(res_temp);
                res_temp.clear();
                depth++;
            }
        }
        return res;
    }
    
};
