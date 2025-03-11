/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void fillParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) {
                q.push(node->left);
                parentMap[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                parentMap[node->right] = node;
            }
        }
    }
    void radialTraversal(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k, 
                         queue<pair<TreeNode*, int>>& qt, unordered_map<TreeNode*, bool>& visited) {
        while (!qt.empty()) {
            int size = qt.size();
            if (qt.front().second == k) break; // Stop if we've reached distance k

            for (int i = 0; i < size; i++) {
                auto [node, dist] = qt.front();
                qt.pop();

                if (node->left && !visited[node->left]) {
                    qt.push({node->left, dist + 1});
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    qt.push({node->right, dist + 1});
                    visited[node->right] = true;
                }
                if (parentMap.find(node) != parentMap.end() && !visited[parentMap[node]]) {
                    qt.push({parentMap[node], dist + 1});
                    visited[parentMap[node]] = true;
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parentMap;
        fillParentMap(root, parentMap);

        queue<pair<TreeNode*, int>> qt;
        unordered_map<TreeNode*, bool> visited;
        qt.push({target, 0});
        visited[target] = true;

        radialTraversal(target, parentMap, k, qt, visited);

        vector<int> result;
        while (!qt.empty()) {
            auto [node, dist] = qt.front();
            qt.pop();
            if (dist == k) result.push_back(node->val);
        }
        return result;

    }
};