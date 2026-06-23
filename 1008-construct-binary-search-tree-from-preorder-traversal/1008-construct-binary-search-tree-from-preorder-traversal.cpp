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

    TreeNode* build(int& index, vector<int>& preorder, int maxVal) {
        if(index >= preorder.size() || preorder[index] >= maxVal) return NULL;

        TreeNode* node = new TreeNode(preorder[index++]);

        node -> left = build(index, preorder, node -> val);
        node -> right = build(index, preorder, maxVal);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(index, preorder, INT_MAX);
    }
};