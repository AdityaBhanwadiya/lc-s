class Solution {
public:
    void inorder(TreeNode* root, int& count, int& ans, int k) {
        if (root == NULL)
            return;
        
        inorder(root->left, count, ans, k); 
        count++;
        if (count == k) {
            ans = root->val;
            return; 
        }
        inorder(root->right, count, ans, k); 
    }

    int kthSmallest(TreeNode* root, int k) {
        int answer = -1, count = 0;
        inorder(root, count, answer, k);
        return answer;
    }
};