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
    TreeNode* helper (TreeNode* root){
        // no left subtree
        if(root->left == NULL)
            return root->right;
        
        // No right subtree
        if(root->right == NULL) 
            return root->left;
        
        // both trees present, connect left's rightmost to right's first.
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if(root->right == NULL) 
            return root;
        return findLastRight(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        
        if(root->val == key)
            return helper(root);
    
        TreeNode* dummy = root;

        while(root != NULL){
            if(root->val > key){
                //go left
                if(root->left != NULL && root->left->val == key){
                    // found key
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }
            else{
                //go right
                if(root->right != NULL && root->right->val == key){
                    // found key
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};