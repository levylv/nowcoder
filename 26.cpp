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
    vector<TreeNode*> v;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree || (!(pRootOfTree->left) && !(pRootOfTree->right))) 
            return pRootOfTree;
        inorderTra(pRootOfTree);
        v[0]->left = NULL;
        v[0]->right = v[1];
		size_t i = 1;     
        for (;i < v.size()-1;i++)
        {
            v[i]->right = v[i+1];
            v[i]->left = v[i-1];      
        }
        v[i]->right = NULL;
        v[i]->left = v[i-1];
        return v[0];
    }

    void inorderTra(TreeNode *pRootOfTree)
    {
        if(pRootOfTree)
        {
            inorderTra(pRootOfTree->left);
            v.push_back(pRootOfTree);
            inorderTra(pRootOfTree->right);
        }
    }
};

// 直接在中序遍历时进行调整

class Solution{
public:
    TreeNode *last = NULL, *head;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree) return NULL;
        ConvertP(pRootOfTree);
        return head;

    }
    void ConvertP(TreeNode* pRootOfTree)
    {
        if (pRootOfTree)
        {
            Convert(pRootOfTree->left);
            pRootOfTree->left = last;
            if (last)
                last->right = pRootOfTree;
            else
                head = pRootOfTree;
            last = pRootOfTree;
            Convert(pRootOfTree->right);
        }
    }
};

