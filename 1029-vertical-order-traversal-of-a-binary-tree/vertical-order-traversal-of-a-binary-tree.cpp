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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});

        map<int, map<int, multiset<int>>> myMap;


        while(!q.empty()) {
            auto [node, coord] = q.front();
            q.pop();
            int v = coord.first;
            int l = coord.second;
            
            myMap[v][l].insert(node->val);

            if(node->left)  q.push({node->left, {v-1, l+1}});
            if(node->right)  q.push({node->right, {v+1, l+1}});
        }

        for(auto it : myMap) {
            vector<int> temp;
            for(auto q : it.second) {
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};