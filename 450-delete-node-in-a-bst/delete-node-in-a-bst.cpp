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
    TreeNode* lastRight(TreeNode* node) {
        if(!node->right)   return node;
        return lastRight(node->right);
    }

    TreeNode* helper(TreeNode* root) {
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRightChild = lastRight(root->left);

        lastRightChild->right = rightChild;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;

        if(root->val == key)
            return helper(root);

        TreeNode* dummy = root;

        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }    
            }else{
                if(root->right && root->right->val == key){
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



// need dummy node
// Search for the element (make sure left/right exist and if left val/ right val equals to key)
// While rewiring, make sure if the key node's left/right exist/not exist

