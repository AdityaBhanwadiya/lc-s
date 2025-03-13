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
    void traverse (TreeNode* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        if(root == NULL)    return;
        minHeap.push(root->val);
        if(root->left)  traverse(root->left, minHeap);
        if(root->right)  traverse(root->right, minHeap);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        traverse(root, minHeap);

        int ans = INT_MIN;
        while(k-- > 0) {
            ans = minHeap.top();
            minHeap.pop();
        }
        return ans;
    }
};