/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int depth(TreeNode* node){
        if(node == NULL) return 0;

        int dp1 = depth(node->left);
        int dp2 = depth(node->right);

        if(dp1==-1) return -1;
        if(dp2==-1) return -1;

        if(abs(dp1-dp2)>1) return -1;

        return max(dp1,dp2)+1;

        
    }
public:
    bool isBalanced(TreeNode* root) {
        
        return depth(root) != -1;
    }
};