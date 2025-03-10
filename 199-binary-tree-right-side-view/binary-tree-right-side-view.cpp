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
    vector<int> rightSideView(TreeNode* root) {
        // level order traversal
        vector<int> result;

        if(!root)   return result;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        map<int, int> myMap;

        while(!q.empty()) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                auto [node, level] = q.front();
                q.pop();

                myMap[level] = node->val;

                if(node->left)  q.push({node->left, level+1});
                if(node->right)  q.push({node->right, level+1});
            }
        }

        for(auto it : myMap) {
            result.push_back(it.second);
        }
        return result;
    }
};