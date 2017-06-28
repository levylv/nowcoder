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
};*/
class Solution {
public:
    int max_depth = 0;
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;
        Preorder(pRoot, 0);
        return max_depth;
    
    }
    void Preorder(TreeNode* pRoot, int len)
    {
        if (pRoot != NULL)
        {
            Preorder(pRoot->left, len+1);
            Preorder(pRoot->right, len+1);
        }
        else
        {
            if (len > max_depth)
            {
                max_depth = len;
            }
        }
    }
};
