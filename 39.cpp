#include <iostream>
using namespace std;

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int len;
        return IsBalanced(pRoot, &len);
    }

    bool IsBalanced(TreeNode *pRoot, int *len)
    {
        if (pRoot == NULL)
        {
            *len = 0;
            return true;
        }
        int left, right;
        if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right))
        {
            int diff = left - right;
            if (diff <= 1 && diff >= -1)
            {
                *len = 1 + (left > right? left : right);
                return true;
            }
        }
        return false;

    }
};
