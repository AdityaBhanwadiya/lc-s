#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse; 

private:
    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = reverse ? root->right : root->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool rev) {
        reverse = rev;
        pushAll(root);
    }

    int next() {
        if (st.empty()) return -1; 

        TreeNode* topNode = st.top();
        st.pop();
        if (reverse) pushAll(topNode->left); 
        else pushAll(topNode->right);       
        
        return topNode->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator left(root, false);  
        BSTIterator right(root, true); 

        int i = left.next();
        int j = right.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = left.next();
            else j = right.next();
        }
        return false;
    }
};
