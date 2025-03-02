class Solution {
private:
    void check(TreeNode* root, vector<int>& ans) {
        if (!root) { 
            ans.push_back(INT_MIN);
            return;
        }

        ans.push_back(root->val);
        check(root->left, ans);
        check(root->right, ans);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;  
        if (!p || !q) return false; 

        vector<int> ans1, ans2;
        check(p, ans1);
        check(q, ans2);

        return ans1 == ans2;
    }
};
