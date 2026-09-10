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
    void solve(TreeNode * root , vector<TreeNode *> & preorder){
        if(root == NULL) return ;

        preorder.push_back(root);
        solve(root->left,preorder);
        solve(root->right,preorder);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode *> preorder;

        solve(root,preorder);

        TreeNode * curr = root;
        for(int i = 1 ; i<preorder.size();i++){
            curr->right = preorder[i];
            curr->left = NULL;
            curr = curr->right;
        }
        
    }
};