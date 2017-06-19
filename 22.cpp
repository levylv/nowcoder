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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<struct TreeNode*> q;
        vector<int> v;
        if (root == NULL) return v;
        q.push(root);
        while (!q.empty())
        {
            v.push_back(q.front()->val);
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        return v;
    }
};
