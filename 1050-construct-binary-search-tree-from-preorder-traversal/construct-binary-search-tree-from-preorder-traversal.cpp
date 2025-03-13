class Solution {
private:
    TreeNode* helper(int& i, vector<int>& preorder, int ub) {  
        if (i == preorder.size() || preorder[i] > ub) return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = helper(i, preorder, root->val);  
        root->right = helper(i, preorder, ub);      

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(i, preorder, INT_MAX);
    }
};
