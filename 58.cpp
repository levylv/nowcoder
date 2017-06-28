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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return true;
        return isSame(pRoot->left, pRoot->right);
    }

    bool isSame(TreeNode* pNode1, TreeNode* pNode2)
    {
        if (pNode1 == NULL && pNode2 == NULL)
            return true;
        if (pNode1 == NULL || pNode2 == NULL)
            return false;
        if (pNode1->val != pNode2->val)
            return false;
        return isSame(pNode1->left, pNode2->right) && isSame(pNode1->right, pNode2->left);
    }

};
