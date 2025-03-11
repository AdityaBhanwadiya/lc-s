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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
    
        auto index = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftInorder (inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder (inorder.begin() + index + 1, inorder.end());
        vector<int> leftPreOrder (preorder.begin()+1, preorder.begin() + index + 1);
        vector<int> rightPreOrder (preorder.begin()+index+1, preorder.end());

        root->left = buildTree(leftPreOrder, leftInorder);
        root->right = buildTree(rightPreOrder, rightInorder);

        return root;


    }
};