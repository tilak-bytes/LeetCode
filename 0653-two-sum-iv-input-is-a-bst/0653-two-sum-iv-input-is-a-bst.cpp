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
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool reverse) : reverse(reverse) {
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if(reverse) pushAll(node->left);
        else pushAll(node->right);

        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root, false);  // inorder → smallest first
        BSTIterator right(root, true);  // reverse inorder → largest first

        int l = left.next();
        int r = right.next();

        while(l < r) {
            if(l + r == k) return true;
            else if(l + r < k) l = left.next();
            else r = right.next();
        }
        return false;
    }
};