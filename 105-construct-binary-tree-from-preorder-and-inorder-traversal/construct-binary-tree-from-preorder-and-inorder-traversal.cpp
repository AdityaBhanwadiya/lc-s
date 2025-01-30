class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr; 
        
        int rootVal = preorder[0];  
        TreeNode* root = new TreeNode(rootVal);
        
        auto it = find(inorder.begin(), inorder.end(), rootVal);
        int rootIndex = distance(inorder.begin(), it);
 
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        
        vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + 1 + rootIndex);
        vector<int> rightPreOrder(preorder.begin() + 1 + rootIndex, preorder.end());
        

        root->left = buildTree(leftPreOrder, leftInorder);
        root->right = buildTree(rightPreOrder, rightInorder);
        
        return root;
    }
};
