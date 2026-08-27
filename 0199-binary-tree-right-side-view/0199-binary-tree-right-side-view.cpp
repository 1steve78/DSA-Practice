class Solution {
public:
    vector<int> ans;

    void rSV(TreeNode* node, int level) {
        if (node == nullptr) return;

        if (ans.size() == level)
            ans.push_back(node->val);

        rSV(node->right, level + 1);
        rSV(node->left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        rSV(root, 0);
        return ans;
    }
};