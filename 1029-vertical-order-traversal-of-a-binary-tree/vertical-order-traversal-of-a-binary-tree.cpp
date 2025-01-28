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
        if(!root) return ans;

        queue<pair<TreeNode* ,pair<int, int>>> q;
        q.push({root, {0,0}});

        map<int, map<int, multiset<int>>> map;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto qItem = q.front();
                q.pop();
                TreeNode* node = qItem.first;
                int x = qItem.second.first; int y = qItem.second.second;

                map[x][y].insert(node->val);

                if(node->left) q.push({node->left, {x-1, y+1}});
                if(node->right) q.push({node->right, {x+1, y+1}});
            }
        }
        for(auto vertical : map){
            vector<int> col;
            for(auto level : vertical.second) {
                col.insert(col.end(), level.second.begin(), level.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};