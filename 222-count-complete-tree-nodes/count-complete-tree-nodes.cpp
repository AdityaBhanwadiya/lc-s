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
private:
    void func (TreeNode* root, int& count) {
        if(!root)   return;
        if(root)    count++;

        if(root->left)  func(root->left, count);
        if(root->right) func(root->right, count);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int count = 0;
        func (root, count);
        return count;
    }
};