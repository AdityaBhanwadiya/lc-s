class Solution {
private:
    bool helper(TreeNode* root, long long minVal, long long maxVal) {
        if (root == NULL) return true;  

        if (root->val <= minVal || root->val >= maxVal) return false;

        return helper(root->left, minVal, root->val) && 
               helper(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
