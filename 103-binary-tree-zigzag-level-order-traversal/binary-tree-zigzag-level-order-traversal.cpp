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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        // 0 -> 1eft to right
        int dir = 1;

        if(root == NULL)
            return ans;

        while(!q.empty()) {
            int size = q.size();

            vector<int> temp;

            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(dir == 0)
                reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            dir = 1 - dir;
        }
        return ans;
    }
};