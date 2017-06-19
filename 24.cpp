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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> path;
        int sum = 0;
        stack<TreeNode *> s;
        TreeNode *cur = root, *last = NULL, *temp;
        if (root == NULL) return res;
        s.push(root);
        while (!s.empty())
        {
            if (cur)
            {
                s.push(cur);
                sum += cur->val;
                path.push_back(cur->val);
                if (cur->left == NULL && cur->right == NULL && sum == expectNumber)
                {
                    res.push_back(path);
                }
                cur = cur ->left;
            }
            else
            {
                temp = s.top();
                if (temp -> right != NULL && temp ->right != last)
                {
                    cur = temp -> right;
                }
                else
                {
                    last = temp;
                    sum -= temp->val;
                    path.pop_back();
                    s.pop();
                }

            }
        }
        return res;

    }
};


//非递归实现有些繁琐，需要知道上一次访问的节点。
//下面用递归实现。


class Solution{
public:
    vector<vector<int>> res;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
    {
        vector<int> path;
        if (!root) return res;
        path.push_back(root->val);
        traveralPath(root, expectNumber, root->val, path);
        return res;
    }

    void traveralPath(TreeNode *root, int expectNumber, int sum,  vector<int> path)
    {
        if (!root->left && !root->right)
        {
            if (sum == expectNumber)
            {
                res.push_back(path);
            }   
        }
        if (root->left)
        {
            path.push_back(root->left->val);
            traveralPath(root->left, expectNumber, sum + root->left->val, path);
            path.pop_back();
        }
        if (root->right)
        {
            path.push_back(root->right->val);
            traveralPath(root->right, expectNumber, sum + root->right->val, path);
            path.pop_back();
        }
    }
};
