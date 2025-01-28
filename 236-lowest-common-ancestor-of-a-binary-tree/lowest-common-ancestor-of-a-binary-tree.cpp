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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return root;

        if(root->val == p->val) {
            return p;
        } else if(root->val == q->val) {
            return q;
        }


        TreeNode* lcaLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* lcaRight = lowestCommonAncestor(root->right, p, q);
        
        if(lcaLeft != NULL){
            if(lcaRight != NULL){
                return root;
            }
            else{
                return lcaLeft;
            }
        }
        else{
            return lcaRight;
        }

    }
};