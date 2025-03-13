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
    bool pathToTarget (TreeNode* root, TreeNode* target, vector<TreeNode* >& ans) {

        ans.push_back(root);
        if(root->val == target->val)  {
            return true;
        }else if(root->val > target->val){
            return pathToTarget(root->left, target, ans);
        }else{
            return pathToTarget(root->right, target, ans);
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> vecP, vecQ;

        TreeNode* ans;

        if(pathToTarget(root, p, vecP) && pathToTarget(root, q, vecQ)) {
            for(int i=0;i<min(vecP.size(), vecQ.size());i++){
                if(vecP[i] != vecQ[i]) {
                    break;
                }else{
                    ans = vecP[i];
                }
            }
        }
        return ans;
    }
};