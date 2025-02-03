class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr; 

        TreeNode* root = new TreeNode(preorder[0]); 
        
        for(int i = 1; i < preorder.size(); i++) {
            TreeNode* dummy = root; 
            TreeNode* newNode = new TreeNode(preorder[i]);

            while (true) { 
                if (preorder[i] < dummy->val) { 
                    if (dummy->left == nullptr) { 
                        dummy->left = newNode; 
                        break;
                    }
                    dummy = dummy->left;
                } else { 
                    if (dummy->right == nullptr) { 
                        dummy->right = newNode; 
                        break;
                    }
                    dummy = dummy->right; 
                }
            }
        }
        return root;
    }
};
