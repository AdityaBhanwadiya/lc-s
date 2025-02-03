class BSTIterator {
    stack<TreeNode*> st;
    bool reverse; // false for in-order, true for reverse in-order

private:
    void pushAll(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = reverse ? root->right : root->left; // Move in the correct direction
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        if (st.empty()) return -1; // Edge case

        TreeNode* node = st.top();
        st.pop();

        if (!reverse) { // Forward iterator (in-order)
            pushAll(node->right); 
        } else { // Reverse iterator (reverse in-order)
            pushAll(node->left);
        }

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false);  // In-order iterator (smallest to largest)
        BSTIterator r(root, true);   // Reverse in-order iterator (largest to smallest)

        int left = l.next();
        int right = r.next();

        while (left < right) {
            if (left + right == k) return true;
            else if (left + right < k) left = l.next();
            else right = r.next();
        }

        return false;
    }
};
