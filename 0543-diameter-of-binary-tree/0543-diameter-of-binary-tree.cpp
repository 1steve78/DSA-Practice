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
public:
    int maxi = 0;
    int diameter(TreeNode* node){
        if(node == NULL) return 0;

        int left = diameter(node->left);
        int right = diameter(node->right);

        maxi = max(maxi,left+right);

        return 1 + max(left,right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
       diameter(root);

       return maxi;
        
    }
};