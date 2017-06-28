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
    vector<TreeNode*> path;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        inorder(pRoot);
        if (k > path.size() || k <= 0)
            return NULL;
        return path[k-1];
        
    }

    void inorder(TreeNode* pRoot)
    {
        if (pRoot != NULL)
        {
            inorder(pRoot->left);
            path.push_back(pRoot);
            inorder(pRoot->right);
        }
    }
    
};
