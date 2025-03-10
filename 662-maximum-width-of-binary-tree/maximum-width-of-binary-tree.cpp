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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q; // Pair<Node, Position>
        q.push({root, 0});

        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long leftIndex = q.front().second;
            long long rightIndex = q.back().second;

            maxWidth = max(maxWidth, static_cast<int>(rightIndex - leftIndex + 1));

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                long long normalizedIndex = index - leftIndex;

                if (node->left) q.push({node->left, 2 * normalizedIndex + 1});
                if (node->right) q.push({node->right, 2 * normalizedIndex + 2});
            }
        }
        return maxWidth;
    }

};