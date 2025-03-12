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
    TreeNode* buildTree (vector<int>& inorder, int ins, int ine, vector<int>& postorder, int pos, int poe, map<int, int>& inMap) {
        if(ins > ine || pos > poe)
            return NULL;
        TreeNode* root = new TreeNode(postorder[poe]);
        int index = inMap[root->val];
        int numsLeft = index - ins;


        root->left = buildTree(inorder, ins, index - 1, postorder, pos, pos + numsLeft - 1, inMap);
        root->right = buildTree(inorder, index+1, ine, postorder, pos+numsLeft, poe-1, inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int, int> inMap;

        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]] = i;

        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap); 
    }
};