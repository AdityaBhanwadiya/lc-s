class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        
        inorder(root->left, ans);  
        ans.push_back(root->val);  
        inorder(root->right, ans); 
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> answer;
        inorder(root, answer);
        return answer[k - 1];  
    }
};
