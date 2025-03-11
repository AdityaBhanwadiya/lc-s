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
private:
    int getHeight (TreeNode* root, string dir) {
        if(!root)   return 0;
        int lh = 0, rh = 0;

        if(dir == "left") {
            while(root){
                lh++;
                root = root->left;
            }
            return lh;
        }
        else {
            while(root){
                rh++;
                root = root->right;
            }
            return rh;
        }
        return 0;

    }
public:
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
    
        int lh = getHeight (root, "left");
        int rh = getHeight (root, "right");

        if(lh == rh)    return pow(2, lh) - 1;
        return 1 + (countNodes(root->left) + countNodes(root->right));
    }
};