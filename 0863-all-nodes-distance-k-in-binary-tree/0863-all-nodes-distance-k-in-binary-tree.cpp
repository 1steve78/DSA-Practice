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
    
    void findK(TreeNode* root, int k, vector<int>& ans) {
        if (root == NULL || k < 0) return;

        if (k == 0) {
            ans.push_back(root->val);
            return;
        }

        findK(root->left, k - 1, ans);
        findK(root->right, k - 1, ans);
    }

    int solve(TreeNode* root, TreeNode* target, int k , vector<int> & ans){
        if(root == NULL) return -1;

        if(root == target ) {
            findK(root,k,ans);
            return 0;
        }

        int left = solve(root->left,target,k,ans);

        if(left != -1 ){
            if(left +1 == k) ans.push_back(root->val);
            else  findK(root->right,k-left-2,ans);
            return left +1;
        }

        int right = solve(root->right,target,k,ans);

        if(right != -1){
            if(right + 1 == k) ans.push_back(root->val);
            else findK(root->left,k - right -2,ans);

            return right +1;
        }

        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        solve(root,target,k,ans);

        return ans;
    }
};