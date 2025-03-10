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
    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& storePath) {
        if (!root) return false;

        storePath.push_back(root); 

        if (root->val == node->val) return true; 

        if (findPath(root->left, node, storePath) || findPath(root->right, node, storePath)) {
            return true;
        }

        storePath.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathToP, pathToQ;
        TreeNode* ans;

        if(findPath(root, p, pathToP) && findPath(root, q, pathToQ)) {
            for(int i=0;i<min(pathToP.size(), pathToQ.size());i++){
                if(pathToP[i] != pathToQ[i]) 
                    break;
                else{
                    ans = pathToP[i];
                }

            }
        }
        return ans;
    }
};