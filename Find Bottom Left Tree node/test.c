/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        int depth = 1,max_depth = 1;
        int res = root->val;
        Recursive(root,depth,max_depth,res);
        return res;
        
    }
    
    void Recursive(TreeNode* node,int depth,int &max_depth,int &res)
    {
        if(!node) return;
        if(depth > max_depth)
        {
            max_depth = depth;
            res = node->val;
        }
        Recursive(node->left,depth+1,max_depth,res);
        Recursive(node->right,depth+1,max_depth,res);
    }
};