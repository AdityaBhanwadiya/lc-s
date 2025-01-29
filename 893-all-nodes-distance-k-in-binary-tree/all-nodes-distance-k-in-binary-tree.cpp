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
public:
    void parentChildren (TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if(!root)   return;

        if(root->left) {
            parentMap[root->left] = root;
        }
        if(root->right) {
            parentMap[root->right] = root;
        }

        parentChildren (root->left, parentMap);
        parentChildren (root->right, parentMap);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0)  return {target->val};
        
        int distance = 0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parentMap;
        unordered_map<TreeNode*, bool> visited;

        parentChildren (root, parentMap);

        q.push(target);
        visited[target] = true;

        while(distance != k) {
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) { 
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]) { 
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parentMap.find(node) != parentMap.end() && !visited[parentMap[node]]){
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }
            }
            distance++;
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};