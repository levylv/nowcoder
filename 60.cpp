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
            vector<vector<int> > res;
            vector<int> res_temp;
            if (pRoot == NULL)
                return res;
            queue<TreeNode* > node;
            node.push(pRoot);
            int to_be_printed = 1;
            int next_level = 0;
            while (!node.empty())
            {
                TreeNode* p = node.front();
                res_temp.push_back(p->val);
                if (p->left != NULL)
                {
                    node.push(p->left);
                    next_level++;
                }
                if (p->right != NULL)
                {
                    node.push(p->right);
                    next_level++;
                }
                node.pop();
                to_be_printed--;
                if (to_be_printed == 0)
                {
                    res.push_back(res_temp);
                    res_temp.clear();
                    to_be_printed = next_level;
                    next_level = 0;
                }
            }
            return res;
        
        }
    
};
