/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode **T;
        TreeNode *bootT;
        bool flag;
        int i=0;
        if (pre.empty() == true)
        {
            exit(0);
        }
        else
        {
            bootT = new TreeNode(pre[0]);
            T = &bootT;
            i++;
            while (i<pre.size())
            {
                while ((*T) != NULL)
                {
                     for (int j=0;j<vin.size();j++)
                    {
                        if (vin[j] == pre[i])
                        {
                            flag = true;
                            break;
                        }
                        if (vin[j] == (*T)->val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    
                    if (flag == true)
                    {
                        T = &(*T)->left;
                    }
                    else
                    {
                        T = &(*T)->right;
                    }
                }
                *T = new TreeNode(pre[i]);
                T = &bootT; //回到根节点
                i++;
            }
            return bootT;

        }
    }

};
